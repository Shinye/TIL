# 4.6 Threading Issues

다중 스레드 프로그램을 설계할 때 고려해야 할 몇 가지 문제들이 있다.



## 4.6.1 fork()와 exec() 시스템 호출

[참고] fork() & exec()

fork()와 exec()는 모두 한 프로세스가 다른 프로세스를 실행시키기 위해 사용하게 됩니다.

```
Every application(program) comes into execution through means of process, 
process is a running instance of a program. 

Processes are created through different "system calls", most popular are fork() and exec()
```



- fork()

```
pid_t pid = fork();
```

fork() **creates a new process by duplicating the calling process**, The new process, referred to as child, is an exact duplicate of the calling process, referred to as parent, except for the following :

1. The **child has its own unique process ID**, so this PID does not match the ID of any existing process group.
2. The child’s parent process ID is the same as the parent’s process ID.
3. The child does not inherit its parent’s memory locks and semaphore adjustments.
4. The child does not inherit outstanding asynchronous I/O operations from its parent nor does it inherit any asynchronous I/O contexts from its parent.

On success, the PID of the child process is returned in the parent, and 0 is returned in the child. On failure, -1 is returned in the parent, no child process is created, and errno is set appropriately.



- exec()

   **exec은 자신의 프로세스를 현재 진행 중인 프로세스 위에 덮어 써버린다.**

  **fork( )는 image(= 소스코드)와 PCB를 전부 복사**하는데, `exec()`의 경우에는 현재 image에 새로운**실행(execute)코드를 디스크로부터 바이너리 파일 형태로 가져온 후**에 **현재 image에 덮어 씌우기(over write)를 진행**하고 **자신 프로세스의 main( )으로 진행하는 것**이다. 한마디로 기존의 작업하던 것을 자신의 프로그램으로 갈아 치우고 자신의 프로그램을 가동시키는 행위라고 할 수 있다.

  The exec() family of functions **replaces** the current process image(== source code) with a new process image. It loads the program into the current process space and runs it from the entry point.

  

----

만약 한 프로그램의 스레드가 fork()를 호출하면...

- 새로운 프로세스는 모든 스레드를 복제해야 하는가? 
- 한 개의 스레드만 가지는 프로세스 여야 하는가?
- ...

=> Unix는 위의 모든 경우를 대응한다.



## 4.6.2 신호 처리

신호는 유닉스에서 프로세스에게 어떤 사건이 일어났음을 알려주기 위해 사용된다. 신호는 알려줄 사건의 근원지나 이유에 따라 동기식 또는 비동기식으로 전달될 수 있다.

- 신호는 특정 사건이 일어나야 생성도니다.
- 생성된 신호가 프로세스에게 전달된다.
- 신호가 전달되면 반드시 처리되어야 한다.

동기식 신호의 예로는 불법적 메모리 접근, 0으로 나누기 등이 있다.

모든 신호마다 커널이 실행시키는 디폴트 신호 처리기이고, 이 디폴트 처리기는 사용자 정의 처리기에 의해 대체될 수 있다. 또한 신호는 항상 프로세스에게 전달된다.

하지만 프로세스가 여러 스레드를 가지고 있는 경우의 신호처리의 경우, 어느 스레드에게 신호를 전달해야 하는가?

- 신호가 적용될 스레드에게 전달
- 모든 스레드에게 전달
- 몇몇 스레드에게만 선택적 전달
- 특정 스레드가 모든 신호를 받도록 지정



이러한 전달 방법은 신호의 유형에 따라 다르다. 예를 들어 동기식 신호의 경우, 그 신호를 야기한 스레드에게 전달한다.<br />그러나 비동기 신호는 전달의 대상이 명확하지 않다. ctrl+c를 입력하여 프로세스를 강제종료하는 신호와 같은 비동기 신호는 그 프로세스 내 모든 스레드에게 전달되어야 한다. 이를 위한 표준 Unix 함수는 다음과 같다. 이 함수는 특정 신호가 전달될 프로세스를 지정한다.

```shell
kill(pid_t pid, int signal);
```



## 4.6.3 스레드 취소 (Cancellation)

스레드 취소는 스레드가 끝나기 전 그것을 강제 종료시키는 작업을 일컫는다. 예를 들어, 여러 스레드들이 데이터베이스를 병렬로 검색하고 있다가, 그 중 한 스레드가 결과를 찾았다면 나머지 스레드들은 취소되도 된다.

이처럼 취소되어야 할 스레드를 목표 스레드라고 부른다. 목표 스레드의 추소는 다음과 같은 두 가지 방식으로 발생할 수 있다.

- 비동기식 취소
  - 한 스레드가 즉시 목표 스레드를 강제 종료
- 지연 취소
  - 목표 스레드가 주기적으로 자신이 종료되어야 할지를 점검한다. 이 경우 목표 스레드가 질서정연하게 강제종료될 수 있는 기회가 만들어진다.

스레드 취소 시 취소 될 스레드들에게 할당된 자원들을 잘 처리해주는 것이 중요하다.

```c++
#include <pthread.h>

int pthread_cancel(pthread_t thread);
```

이 함수는 인자로 주어진 쓰레드 식별번호 thread를 가지는 쓰레드를 중지시킨다. 명확히 말하자면 쓰레드를 중지 시키는게 아니고 쓰레드에 취소 요청을 하는 것으로 봐야 한다. 취소 요청을 받은 쓰레드가 어떻게 반응 할런지는 요청을 받은 쓰레드의 취소 상태 설정에 의존한다. 취소 요청을 받은 쓰레드는 취소 상태에 의해서 필요한 작업을 한 후 종료 하게 된다. 취소 요청을 받아서 종료하는 쓰레드는 pthread_exit(PTHREAD_CANCELED)를 호출하고 종료한다. pthread_cancel()에 의해서 취소가 통보된 쓰레드는 쓰레드 취소 상태의 설정에 따라서 취소 요청을 무시할 수도 취소지점(cancellation point) 지점까지 수행한뒤에 종료 될수도 있기 때문이다.

스레드의 취소 가능성 상태는 `pthread_setcancelstate(3)`로 결정하며 *활성*(새 스레드의 기본값)이거나 *비활성*일 수 있다. <br />(PTHREAD_CANCEL_DISABLE와 PTHREAD_CANCEL_ENABLE)<br />스레드에서 취소를 비활성화했으면 다시 취소를 활성화할 때까지 **취소 요청이 큐에 남아 있는다**. 스레드에서 취소를 활성화했으면 취소 가능성 유형이 취소 발생 시점을 결정한다.



### 취소지점

쓰레드에게 취소요청이 왔다고 해서 무조건 취소해 버리면 문제가 생길 수도 있다. 어떤 일을 처리하고 있는 중에 취소요청이 전달했는데, 별로 중요하지 않는 (무시해도 될만한) 일이라면 중단후 바로 취소해도 되겠지만 중요한 일을 처리하는 중이라면 일을 처리한후 종료 해야 할것이다. 이 마지 노선이 취소지점이다. 취소지점으로 설정될 수 있는 영역은 다음과 같다.

- pthread_join(3)
- pthread_cond_wait(3)
- pthread_cond_timedwait(3)
- pthread_testcancel(3)
- sem_wait(3)
- sigwait(3)

`pthread_setcancelstate()` 함수에 의해서 `PTHREAD_CANCEL_ENABLE` 상태로 되어 있다면 취소지점을 무시하고 즉시 종료 된다. 

`PTHREAD_CANCEL_DISABLE` 로 되어 있다면 위의 취소지점을 벗어날 때까지 기다린다. 즉 취소요청을 받은 쓰레드가 pthread_cond_wait()에서 조건변수를 기다리는고 있다면 조건변수 를 받을 때까지 취소를 유보하게 된다.



### 스레드 종료 시 자원 해제

쓰레드에서 malloc()등을 호출해서 메모리 공간을 확보했다거나 DB나 파일, 소켓등을 열어서 작업했다면 반드시 이들 자원을 해제시켜줘야 한다. 

간단하게 생각하자면, 쓰레드 종료시점에서 free(), close(), DB라면 이런 저런 정리를 해주면 될것이다. 그러나 pthread_cancel()등에 의해서 작업중간에 요청을 받았다면 그리 간단한 문제가 아니다. 쓰레드 마지막까지 루틴을 진행할 수 없기 때문이다. 이럴 경우를 대비해서 pthread_cleanup_push(), pthread_cleanup_pop()와 같은 함수를 제공한다.

이 함수들을 이용해서 쓰레드가 종료할 때 호출해야할 함수를 지정할 수 있다. 그러므로 프로그래머는 이들 함수에 자원해제와 같은 필요한 코드를 넣어두기만 하면 된다. 



## 4.6.4 TLS (Thread Local Storage)

멀티 쓰레드 프로그래밍을 하다보면 불편한게 있다. 쓰레드별 고유한 전역변수(또는 정적변수) 사용하기가 어렵다는 것. 쓰레드를 그냥 만들면 쓰레드에게 주어진 혼자만의 공간은 지역적인 stack영역 뿐이다. 

일반적인 전역변수는 모두가 공유할 수 있는 data영역에 저장된다. 

그렇다고 힙에 만들어도 private 힙이 아닌 이상 역시나 공유되는 공간이다. 그리고 int하나를 위해서 private 힙을 만드는 것은 말이 안된다. 스레드가 특정 함수만을 반복적으로 수행하면 별로 필요없다고 생각할 수 도 있는데, 막상 없으면 아쉽고 쓸려면 없다. Thread Local Storage(이하 TLS)가 이러한 문제를 해결해준다.



![img](https://camo.githubusercontent.com/e2c67d56639025c54b73ed9c3d15e03359820eb7/68747470733a2f2f692d6d73646e2e7365632e732d6d7366742e636f6d2f64796e696d672f49433439353833372e706e67)



각각의 스레드는 고유한 스택을 갖기 때문에 스택 변수(지역 변수)는 스레드 별로 고유하다.<br />예를 들어 각각의 스레드가 같은 함수를 실행한다고 해도 그 함수에서 정의된 지역 변수는 실제로 서로 다른 메모리 공간에 위치한다는 의미이다. 그러나 정적 변수와 전역 변수의 경우에는 프로세스 내의 모든 스레드에 의해서 공유된다.

위의 특성에 의거, **TLS는 정적, 전역 변수를 각각의 스레드에게 독립적으로 만들어 주고 싶을 때 사용**하는 것이다. 다시 말해, 분명히 같은 문장(context)을 실행하고 있지만 실제로는 스레드 별로 다른 주소 공간을 상대로 작업하는 것이다.



## 4.6.5 스케쥴러 액티베이션

(무슨말인지...잘 모르겠어요...)

사용자 스레드 라이브러리와 커널 스레드간 통신은 스케줄러 액티베이션 방법을 사용한다.

n:n 모델의 시스템들은 사용자/커널 스레드 사이에 중간 자료구조를 둔다. 이 자료구조를 LWP(Light Weight Process) 라고 부른다.

(공부 더 하고 돌아오겠습니다...)





# 4.7 운영체제 사례

Window와 Linux에선 스레드를 어떻게 구현하는가?



## 4.7.1 Window Thread

### Window API

MS에서 나오는 모든 운영체제의 기본이 되는 API. 스레드의 일반적인 구성요소는 다음과 같다.

- 스레드 ID
- 처리기의 상태를 나타내는 레지스터 집합
- 사용자 모드에서 실행될 때 필요한 사용자 스택, 커널 모드에서 실행될 때 필요한 커널
- 실행 시간 라이브러리와 동적 링크 라이브러리 등이 사용하는 개별 데이터 저장영역

![img](https://t1.daumcdn.net/cfile/tistory/2551F935542CF0690D)



### Linux Thread

- 프로세스를 복제하는 기능을 가진 fork()시스템 호출을 제공한다.또한 clone()시스템 호출로 스레드를 생성할 수도 있다. 
- 그러나 리눅스는 프로세스와 스레드를 구별하지 않는다.
- 사실 리눅스는 프로그램 내의 제어 흐름을 나타내기 위해 프로세스, 스레드라는 이름 보다는 태스크라는 용어를 사용한다.



### References

[Difference between fork() and exec()](https://www.geeksforgeeks.org/difference-fork-exec/)<br/ >[리눅스 커널 운영체제 강의노트3]([https://medium.com/pocs/%EB%A6%AC%EB%88%85%EC%8A%A4-%EC%BB%A4%EB%84%90-%EC%9A%B4%EC%98%81%EC%B2%B4%EC%A0%9C-%EA%B0%95%EC%9D%98%EB%85%B8%ED%8A%B8-3-9ed24cf457ce](https://medium.com/pocs/리눅스-커널-운영체제-강의노트-3-9ed24cf457ce)) <br />[스레드의 취소와 종료](https://www.joinc.co.kr/w/Site/Thread/Advanced/ThreadCancle)<br />[manpages-pthread_cancel(3)](https://github.com/wariua/manpages-ko/wiki/pthread_cancel(3)) <br />[Thread Local Storage](https://ozt88.tistory.com/37)

[TLS](http://egloos.zum.com/sweeper/v/1985738)<br />[activations.pdf](https://cs.nyu.edu/rgrimm/teaching/sp07-os/activations.pdf)