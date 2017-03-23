# IO Redirection

Input / Output / Redirection -> 방향을 바꾼다<br>
기존의 아웃풋은 모니터에 바로 출력이 되지만, 모니터가 아닌 다른 곳에 결과 값을 출력시키는 것을 의미 (명령어의 실행 결과 값을 새로운 파일에 출력하는 방법 등…)<br><br>

## Output
예를 들어,<br>

```
Desktop ls -l > result.txt
```

ls -l의 결과가 모니터에 출력되는 대신 result.txt 라는 파일 안에 저장된다.<br>
**출력되는 방향을 다른 곳으로 돌려 다른 파일에 저장되게 함.** 이를 `Redirection` 이라 한다.

![Unix Programs](https://68.media.tumblr.com/1979a24777f8cbd1e4a051fec4be1a69/tumblr_oka802OqJ11v80c66o1_540.png)<br>
#### Unix Process
명령어(ls, mkdir, apt get, ps(process list)…) , 프로세스(하드디스크 위에 저장되어있던 프로그램이 실행을 위해 메모리 위에 적재되어 CPU에 의해 실행되는 프로그램)
#### input
- Program arguments (ex. ls `-al` : `-al`은 ls라는 프로그램에 입력으로 들어오는 입력 값. 파일 목록 중 숨김파일까지 보여주며(-a), 파일의 권한까지 보여줌(-l) 이라는 옵션. 이 경우는 정확히는 Command-line Arguments)
- Environment variables (환경변수)
- Standard input (CLI 환경에서의 일반적인 데이터 입력)


process가 실행된 후의 일반적인 결과는 `standard output`으로써 결과가 나옴. 에러가 났을 시엔 `standard error` 로써 결과가 나온다. <br> `standard error`의 경우, 위의 예시 처럼 왼쪽으로 열린 꺽새(>)를 써서 에러메세지를 다른 파일에 저장시키고자 하는 redirection이 적용되지 않는다. 왜냐하면 왼쪽으로 열린 꺽새(>)는 standard output을 위한 것이기 때문이다.

예를 들어 만약 rename2.txt를 삭제하는 명령어를 수행하고, 에러가 있을 시 error.log에 오류메세지를 저장하고자 할 때

```
rm rename2.txt > error.log 
# error.log에 아무런 결과도 남지 않음.
```
이 경우는 사실 `>` 앞에 디폴트 값으로 1이 생략되어 있는 것이다. `1>` 은 `standard output`을 위할 때 쓴다. 따라서 에러메세지 로그를 남기고 싶다면

```
rm rename2.txt 2> error.log
# rm명령어 실행 과정에서 오류가 날 시, error.log에 정상적으로 오류메세지가 남는다.
```
스탠다드 에러라고 하는 정보를 리다이렉션 출력 하고자 한다면 > 대신 `2>`를 쓰면 된다.<br>
또한, 다음과 같은 응용 역시 가능하다.<br>

```
rm rename2.txt 1> result.txt 2> error.log 
```
명령어를 실행 후 standard output이 있을 시엔 `>` 인 result.txt에 아웃풋이 저장되고,<br> 스탠다드 아웃풋이 아닌 standard error(에러메세지)가 있을 시엔 그 에러메세지는 `2>`인 error.log에 저장된다.<br><br>



### >> : 로그 '누적'을 위함

![https://68.media.tumblr.com/bdbcc925d3308cb18eace63dbfd4c498/tumblr_okqsrb6QlV1v80c66o1_400.png](https://68.media.tumblr.com/bdbcc925d3308cb18eace63dbfd4c498/tumblr_okqsrb6QlV1v80c66o1_400.png)

output 역할을 하는 꺽새가 한 개 있을 때와 두 개 있을 때는 차이가 있다.<br>

위의 예시와 같이 꺽새가 두 번 있을 땐 해당 명령 ( `date >> date2.log` ) 을 실행할 때 마다 로그 파일에 명령 실행 결과가 **누적**되어 기록된다. 

반면, 꺽새가 한 번 있을 땐 해당 명령 ( `date > date.log` ) 이 실행될 때 로그파일에 결과 값이 누적되지 않는다.



활용 예시로는 `crontab` 에 명령문을 입력할 때, 다음의 명령어를 정기적으로 실행시켜 로그 값을 누적시킬 때 활용할 수 있다. 

```shell
$ */1 * * * * date >> date.log 2> &1
# 1분에 한 번씩
# 명령어 date를 실행시킨 결과값(Standard Output)을 date.log에 저장하며
# 만약 명령어 date 실행 시 오류(Standard Error)가 나도(2>)
# 그대로 표준출력 로그(date.log)에 기록하게 한다. (&1)
# Output에서 숫자 1은 표준출력, 숫자 2는 표준오류를 의미한다.
# 만약 &1 대신 1을 입력하면 1이라는 이름의 파일이 만들어져 그 파일에 에러 메세지가 저장되게 되므로 숫자 앞에 &를 붙여주자.

$ */1 * * * * date 2>> error.log
# >>도 마찬가지로 앞에 1이 생략되어 있는 것이므로 에러 로그를 누적하고 싶다면 2>>를 작성해주면 된다.
```

## Input

프로그램은, 컴퓨터의 하드디스크나 SSD에 저장되어있는 코드를 보통 `프로그램`이라 부름.<br>
이 프로그램이 실행되면, 그 실행되고 있는 상태를 `프로세스`라고 한다.
하나의 프로그램은 여러개의 프로세스를 가질 수 있다.

프로세스는 스탠다드 아웃풋, 스탠다드 에러 : 두가지의 출력 형식을 가지고 있었다.
그리고 한 가지의 입력 형식이 들어있는데, 그것은 `스탠다드 인풋`이다. 하나의 인풋과 두개의 아웃풋 존재.

예를 들어, cat이란 명령어를 입력하면, 사용자가 키보드를 통해 입력하는 정보를 받는다.
unix process : cat / 사용자가 키보드로 입력한 정보 : standard input

```
$ cat
  hello
  > hello
  repeat after me!
  > repeat after me!
# 종료하고 싶을 땐 ctrl + d  
```

[그 외...]<br>
**head 명령어**<br>
파일의 앞부분을 보여주는 명령어<br>

```
head -n1 hello.txt #hello.txt의 첫번째 줄만 보여줌
head -n1 < hello.txt > first_line.txt #hello.txt의 첫번째 줄을 first_line.txt에 저장시킨다. 표준입력과 표준 출력에 대한 리다이렉션을 모두 한 것.

```


