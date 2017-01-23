#IO Redirection

Input / Output / Redirection -> 방향을 바꾼다<br>
기존의 아웃풋은 모니터에 바로 출력이 되지만, 모니터가 아닌 다른 곳에 결과 값을 출력시키는 것을 의미 (명령어의 실행 결과 값을 새로운 파일에 출력하는 방법 등…)<br><br>

###Output
예를 들어,<br>

```
➜ Desktop ls -l > result.txt
```

ls -l의 결과가 모니터에 출력되는 대신 result.txt 라는 파일 안에 저장된다.
출력되는 방향을 다른 곳으로 돌려 다른 파일에 저장되게 함 => “Redirection"
http://slideplayer.com/slide/5126304 // 쉘스크립트 가이드에 좋음!

동그라미 : 명령어(ls, mkdir, apt get, ps(process list)…) , 프로세스...
input : program arguments (ex. ls -al : -al은 ls라는 프로그램에 입력으로 들어오는 입력 값. 이 경우는 정확히는 Command-line Arguments)

process가 실행된 후의 일반적인 결과는 standard output.
에러가 났을 시엔 standard error. 꺽새를 써서 에러메세지를 다른 파일에 저장시키고자 하는  redirection을 쓰고자 했다면 안됨. 꺽새는 standard output을 위한 것이기 때문이다.

rm rename2.txt > error.log // 에는 > 앞에 디폴트 값으로 1이 생략되어 있는 거고, 1>은 standard output을 위함을 뜻한다. 따라서 에러메세지 로그를 남기고 싶다면
rm rename2.txt 2> error.log // 스탠다드 에러라고 하는 정보를 리다이렉션 출력 하고자 한다면  2>를 쓰쟈!

rm rename2.txt 1> result.txt 2> error.log // 명령어를 실행 후 standard output이 있을 시엔 result.txt에 아웃풋이 저장되고, 스탠다드 아웃풋이 아닌 standard error(에러메세지)가 있을 시엔 그 에러메세지는 2>인 error.log에 저장된다.

log확장자???

<Input>
프로그램은, 컴퓨터의 하드디스크나 SSD에 저장되어있는 코드를 보통 ‘프로그램’이라 부름
이 프로그램이 실행되면, 다시말해 살아나면 그 실행되고 있는 상태를 ‘프로세스’라고 한다.
하나의 프로그램은 여러개의 프로세스를 가질 수 있다.

프로세스는 스탠다드 아웃풋, 스탠다드 에러 : 두가지의 출력 형식을 가지고 있었다.
그리고 한 가지의 입력이 들어있는데, 스탠다드 인풋이 있다. 하나의 인풋과 두개의 아웃풋 존재

*****cat - enter- blahblah - >blahblah출력
그만하고 싶으면 ctr+d 입력…이게 뭐람?

cat이란 명령어를 입력하면, 사용자가 키보드를 통해 입력하는 정보를 받는다.
unix process : cat / 사용자가 키보드로 입력한 정보 : standard input

cat명령어
* cat hello.txt 와 cat < hello.txt 의 차이? ~그다지 실용적이지는 않은 내용~
cat hello.txt에서의 hello.txt는 cat 명령어의 Command-line Arguments로써 인식된다.
cat < hello.txt에서의 hello.txt는 표준 입력(standard input)으로 cat에게 input을 시킴.

* head 명령어 : 파일의 앞부분을 보여주는 명령어
head -n1 hello.txt // hello.txt의 첫번째 줄만 보여줌
head -n1 < hello.txt > first_line.txt // hello.txt의 첫번째 줄을 first_line.txt에 저장시킨다. 표준입력과 표준 출력에 대한 리다이렉션을 모두 한 것입니다

source 파일 => 파일 실행시킨다는 의미

<bin 디렉토리에 대해 알아봅시다>

/bin

- 리눅스의 기본 명령어(binary)들이 들어있는 디렉토리

- 시스템을 운영하는데 기본적인 명령어들이 들어 있음.

- c 컴파일러로 컴파일되어 있어 이진수로 이루어져 있다.

명령어 df

- 리눅스 파일시스템 사용량 확인

- 리눅스 디스크 사용량 확인

- 리눅스 디스크 용량 확인

명령어 proc

- 프로세스를 볼 수 있다.

명령어 htop

명렁어 media

USB 등 미디어 파일을 올림

명령어 mnt(mount)

본체 안의 하드를 올림

명령어 sudo

슈퍼유저를 흉내낼 수 있다(?)

명령어 sbin

standalone Binary File

시스템의 시작에 필요한 파일을 포함

명령어 etc

boot

부팅할 때 만들어주는 텍스트 파일

share

서현오빠 왈 : 윈도우처럼 프로그램즈같은데 깔리면 얼마나 좋겠어요..

대신 리눅스는 어플리케이션이 usr/share 에 보통 깔립니다.

*실행 파일은 주로 여기 깔리고, config 파일은 보통 etc에 깔린다.

/etc/init.d 파일 :  모든 리눅스 프로세스의 최상위에 위치

var : 주로 외부랑 통신하는 용도로 쓰인다.

/var/mail : 메일 서버를 깔면 메일이 여기로 온다..!

var/spool : 프린트 하는 거

var/www : 아파치