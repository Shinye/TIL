# Thread

## 4.1 개요

- 스레드는 CPU이용의 기본 단위이다. 
- 프로세스 내에서 프로그램 명령을 실행하는 기본 단위이자 흐름, 개체라고 할 수 있다.
- 스레드는 스레드ID, 프로그램 카운터, 레지스터 집합, 그리고 스택으로 구성된다.
- 스레드는 같은 프로세스에 속한 스레드와 코드, 데이터 섹션, 열린 파일, 신호와 같은 운영체제 자원을 공유한다.

![단일스레드 다중스레드](https://mblogthumb-phinf.pstatic.net/20150417_202/three_letter_1429254488468egL0u_JPEG/4_01_ThreadDiagram.jpg?type=w2)

### 단일 스레드

- 하나의 프로세스에서 하나의 스레드 실행

- 하나의 레지스터와 스택으로 표현

### 멀티 스레드

- 프로그램을 다수의 실행 단위로 나누어 실행
- 프로세스 내에서 자원을 공유하여 자원생성과 관리의 중복을 최소화
- 서버가 많은 요청을 효율적으로 수행할 수 있는 환경을 제공
- 각각의 스레드가 고유의 레지스터와 스택으로 표현됨



### 4.1.2 동기

- 현대의 거의 모든 소프트웨어는 다중 스레드
- 하나의 응용 프로그램이 여러 개의 비슷한 작업들을 수행해야 할 때, 그때그때 새 프로세스를 생성하는 것을 비효율적
  - 스레드를 새로 생성하는 것 보다 프로세스를 새로 생성하는것이 훨씬 더 많은 시간 소요
  - 예를 들어 웹서버는 여러개의 클라이언트로부터 병행적으로 접근이 가능한데, 단일 스레드로 한번에 하나의 클라이언트만 서비스할 수 있다면 매우 비효율적일 것.
  - 웹 서버가 다중 스레드화 되면, 클라이언트의 요청을 listen하는 스레드, 요청을 실행할 스레드 등 다양한 스레드를 만들어 작업을 진행할 수 있다.
  - RPC 역시도 다중 스레드 시스템으로 구현된다.



### 4.1.3 장점

- 응답성
  - 대화형 응용을 다중 스레드화 하면, 응용 프로그램의 일부분이 봉쇄되거나, 또는 응용 프로그램이 긴 작업을 수행하더라도 프로그램의 수행이 계속됨을 허용함으로써 사용자에 대한 응답성이 증가한다.
- 자원 공유
  - 프로세스는 공유메모리 혹은 메세지를 통해서만 자원 공유가 가능하지만,
  - 스레드는 자동적으로 자신이 속한 프로세스의 자원들과 메모리를 공유한다.
- 경제성
  - 프로세스 생성을 위해 메모리와 자원을 할당하는 것은 비용이 많이 든다. 
  - 스레드는 자신이 속한 프로세스의 자원들을 공유하기 때문에, 스레드를 생성하고 문맥교환하는 것이 더 낫다.
- 규모 적응성
  - 다중처리를 해야 할 상황일 시, 각각의 스레드가 다른 처리기에서 병렬로 수행될 수 있다.



## 4.2 다중(멀티) 코어 프로그래밍

다중코어란 동일한 성능으로 작동하는 CPU 여러 개를 1개의 칩 속에 집적해 놓은 것이다. (컴퓨터 내에서 실질적인 연산처리를 수행하는 CPU가 여러개의 코어로 구성되어 있다는 것을 의미.)

- 각 코어는 운영체제에게 독립된 처리기로 보인다.
- 다중 스레드 프로그래밍은 다중 계산 코어를 더 효율적으로 사용할 수 있고, 병행 실행을 더 향상시킬 수 있는 기법을 제공.
- 하나의 코어(CPU)는 한번에 오직 하나의 스레드만 실행할 수 있다.
  - 따라서 단일 코어 시스템 상에서 병행성은 그저 스레드의 실행이 시간에 따라 교대로 실행되는 것
  - 하지만 다중 코어 시스템은 시스템이 개별 스레드를 복수의 각 코어의 배정할 수 있기 때문에 병행성을 가질 수 있다.



----



### [참고] Concurrency !== Parallelism

<https://dev.to/roperzh/concurrency--parallelism-55h5>

### Concurrency (동시성 / 병행)

모든 태스크가 징행하게끔 함으로써 하나 이상의 태스크를 수행시킨다.

Concurrency is all about doing tasks in the same *interval of time*. The important detail here is that the tasks don’t necessarily execute *at the same time*, but they can be divided into smaller tasks that can be interleaved.

![concurrency](https://res.cloudinary.com/practicaldev/image/fetch/s--5jo_D9Hp--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://user-images.githubusercontent.com/4419992/35572695-ee6275c8-05b3-11e8-8460-2c1ac7081574.jpg)



A good place where concurrency takes place is in the kitchen, imagine a single chef cutting lettuce while is also checking from time to time something in the oven. He has to stop cutting, check the oven, stop checking the oven and then start cutting again, and repeat the process until is done.

As you can see, concurrency is mostly related to the *logistics*, without concurrency, the chef will have to wait until the meat in the oven is ready in order to cut the lettuce.



### Parallelism (병렬)

하나 이상의 태스크를 동시에 수행할 수 있는 시스템

Parallelism, on the other hand, is about doing tasks *literally at the same time*, as the name implies they are executed in parallel.

![parallelism-bw](https://res.cloudinary.com/practicaldev/image/fetch/s--7LZI52RC--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://user-images.githubusercontent.com/4419992/35572701-f14520f6-05b3-11e8-9989-f4dcc7fc987e.jpg)

Back in the kitchen again, now we have two chefs, one can take care of the oven, while the otter cuts the lettuce, we split the work at the expence of having another chef.

Parallelism is a subclass of concurrency: before you execute multiple tasks simultaneously, you first have to manage multiple tasks.



- CPU스케쥴러는 시스템의 프로세스 사이를 빠르게 오가며 모든 프로세스를 진행시켜 마치 병렬 실행이 되는듯 보이도록 설계
  - 사실은 병행실행 되고 있는 것.



### 4.2.2 병렬 실행의 유형

병렬 실행에는 크게 `데이터 병렬 실행` 과 `태스크 병렬 실행` 두 가지가 있다.

- 데이터 병렬실행: 동일한 데이터의 부분집합을 다수의 계산 코어에 분배한 뒤, 각 코어에서 동일한 연산을 실행시킴
- 태스크 병렬실행: 태스크를 다수의 코어에 분배하여, 각 스레드는 고유의 연산을 실행. 



## 4.3 다중 스레드 모델

스레드는 사용자 수준의 사용자 스레드, 커널 수준의 커널 스레드가 제공된다. <br />사용자 스레드는 커널 위에서 지원되며, 커널 스레드는 운영체제에 의해 지원되고 관리된다.



### 다대일 모델

- 많은 사용자 수준의 스레드를 하나의 커널 스레드로 mapping하는 것.

- 한 스레드가 봉쇄형 시스템 (e.g. [Blocking I/O](https://asfirstalways.tistory.com/348)) 을 호출할 경우 전체 프로세스가 봉쇄된다.

  - 참고로 Blocking I/O는 커널 수준에서 실행된다. 사용자 수준의 프로세스가 커널 프로세스에 요청해야 하는 것.

- 또한 한 번에 하나의 스레드만이 커널에 접근할 수 있기 때문에, 다중 스레드가 다중 코어 시스템에 병렬로 실행될 수 없다.

  - 진정한 병렬 실행을 획득할 수 없다.

  ![img](https://mblogthumb-phinf.pstatic.net/20150417_300/three_letter_1429254704655UPg3B_JPEG/4_05_ManyToOne.jpg?type=w2)

### 일대일 모델

- 각 사용자 스레드를 각각 하나의 커널 스레드로 mapping한다.
- 이 모델은 하나의 스레드가 봉쇄형 시스템 호출을 하더라도 다른 스레드 실행 가능
  - 다대일 모델보다 더 많은 병렬성 제공
- 단점은 사용자 수준의 스레드를 생성할 때 그에 따른 커널 스레드를 일일이 또 생성해야 하는 점.
  - 커널 스레드를 생성하는 오버헤드가 응용 프로그램의 성능을 저하시킬 수 있음.



### 다대다 모델

- 여러개의 사용자 수준 스레드와 그보다 작은 수, 혹은 같은 수의 커널 스레드로 멀티플랙스 하는 모델

  ![img](https://mblogthumb-phinf.pstatic.net/20150417_267/three_letter_1429255341628gacRD_JPEG/4_07_ManyToMany.jpg?type=w2)



## 4.4 스레드 라이브러리

프로그래머에게 스레드를 생성하고 관리하기 위한 API를 제공

### 스레드 라이브러리 구현 방법

   1) 커널의 지원없이 완전히 사용자 공간에서만 라이브러리를 제공하는 것

   2) 운영체제에 의해 지원되는 커널 수준 라이브러리를 구현하는 것

- 비동기 스레딩
  - 부모가 자식 스레드를 생성한 후, 부모는 자신의 실행을 재개하여 부모와 자식 스레드가 병행하게 실행됨.
  - 각 스레드는 모든 다른 스레드와 독립적으로 실행하고 부모 스레드는 자식의 종료를 알 필요 없음.
  - 서로 독립적으로 움직이기 때문에 스레드 사이의 데이터 공유는 거의 없는 편.
- 동기 스레딩
  - 부모 스레드가 하나 이상의 자식 스레드를 생성하고, 자식 스레드가 모두 종료될때까지 기다렸다가 자신의 실행을 재개하는 방법.
  - `포크-조인` 전략이라고 부른다.



 ### Pthreads

POSIX(IEEE 1003.1c)가 스레드 생성과 동기화를 위해 제정한 표준 API



### Java 스레드(Java Thread)

- 모든 Java 프로그램은 적어도 하나의 단일 제어 스레드를 포함
- Java 프로그램에서 스레드를 생성하는 기법

​    1) Thread 클래스로부터 파생된 새로운 클래스를 생성하고, Thread 클래스의 run() 매서드를 무효화(override)하는 것

​    2) Runnable 인터페이스를 구현하는 클래스 정의

