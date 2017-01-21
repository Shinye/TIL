#Linux ; 파일의 위치를 찾는 법
###locate<br>
파일에 대한 정보를 담고 있는 DB(mlocate)를 뒤져 결과 값을 도출해낸다. <br>다른 명령어들과 다르게 Directory에 직접적으로 접근하지 않는다. 디렉토리에 직접 접근하는 다른 명령어들보다 비교적 성능이 좋지만 파일 위치의 실시간 반영이 어렵다는 단점이 있다. 리눅스에서 주기적으로 `updatedb` 라는 명령어를 실행해주어 DB에 지속적으로 변경사항이 반영될 수 있게끔 한다.

`updatedb`는 파일시스템을 검색하여 지금 존재하고 있는 파일들의 목록을 데이터베이스화 하는 역할을 한다.(root 권한)<br>

###find
[참조문서](http://www.binarytides.com/linux-find-command-examples/)<br>
Directory에 접근하여 파일을 찾음. 따라서 locate와 다르게 실시간으로 파일의 위치 및 상태를 반영함. <br>

1) root 디렉토리 ( / ) 에서 부터 log 확장자의 파일을 찾음.

```
$ find / -name *.log
# root디렉토리부터의 검색이다 보니 find명령어를 실행하다 보면 permission denied가 발생할 수 있음. 
# 그럴 땐 명령어 앞에 sudo를 붙여주면 됨.
```

2) 내 홈 디렉토리 ( ~ ) 에서 부터 log 확장자의 파일을 찾음.

```
$ find ~ -name '*.log'
```

3) 현재 내가 있는 디렉토리 ( . ) 에서 부터 log 확장자의 파일을 찾음.

```
$ find . -name '*.log'
```

4) 찾고자 하는 것의 타입이 f(파일) 형식이 아닌 것은 제외. (ex. tech.html 라는 이름의 폴더는 제외됨)

```
$ find . type f -name 'tech.html'
```

5) 'tech.html'을 찾아 그 파일 지우기.

```
$ find . -name 'tech.html' -exec rm -f {} \;
# -exec : executive의 약자. 후술될 명령어를 실행하라는 뜻
# rm : remove의 약자. 삭제 명령어
# -f : rm 명령어의 옵션 중 하나로 묻지도 따지지도 않고 지우라는 뜻. (force의 약자)
# {} : find 명령의 결과(-exec 전까지) 를 담는 공간. rm -f {검색결과} 의 형태.
```


###whereis
whereis는 실행파일(명령어 포함)의 실행파일위치, 소스위치, man 페이지파일의 위치를 찾아주는 명령어이다.<br>

```
$ whereis find
/bin/find /usr/bin/find /usr/share/man/man1/find.1.gz
```
<br>

###$PATH<br>
리눅스 환경의 중요한 환경변수 중 하나. 변수명 앞에 달러 표시를 하면 환경변수라는 뜻.<br>
<br>
**환경변수란?**<br>
OS레벨에서 "자주 사용하는" 또는 "필요한" 변수들을 미리 선언해 놓는 것이다.<br>
본인 컴퓨터의 환경변수 목록을 보고 싶다면 `printenv`,`export` 등의 명령어를 쓰면 된다.<br>
특정 환경변수에 대해서 확인하고 싶다면 `echo $환경변수명 을 쓰면 된다.`<br>

```
$ echo $PATH
/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin 
# 리눅스/유닉스 환경에선 디렉토리 사이의 구분을 ;가 아닌 :로 한다.
```
<br>
리눅스 쉘에서 어떤 프로그램을 실행시킬 때, 그 실행 바이너리(실행파일)이 있는 디렉토리로 이동해서 ./programName 과 같이 직접 실행할 수도 있다. <br>
하지만 PATH 환경변수에 그 디렉토리의 경로를 미리 등록해놓으면, 그 디렉토리로 이동하지 않고도 어디에서든 programName 이라는 명령어 만으로도 실행이 가능해진다.
예를 들어 vim 편집기를 실행하려 한다면, 원래 실제 vim 프로그램의 실행파일은

```
$ whereis vim
/usr/bin/vim
```

다음과 같이 /usr/bin 밑에 vim 이라는 실행 파일이 있다.<br>
하지만 우리가 /usr/bin 까지 이동하지 않고 어디에서든 vim test.cpp 와 같은 명령으로 vim프로그램을 실행할 수 있는 이유는 PATH라는 환경변수에 /usr/bin 경로가 이미 등록되어 있기 때문이다.
<br><br>
**환경변수 설정**은 `export` 명령어를 써서 바로 설정 할 수도 있지만, 이런 설정은 일시적이라 터미널을 재시작 하면 설정이 사라진다. 따라서 `.bashrc` 혹은 `.zshrc` (본인의 쉘인터프리터 종류에 따라 이름이 다르다! 확인할것.) 등을 수정해서 사용하는 것이 권장된다.<br><br>
예를 들어 환경변수 PATH에 hadoop 프로그램과 관련하여 새로운 설정을 추가할 경우<br> `vim .bashrc` 명령어를 사용하여 .bashrc 파일을 연 후, 가장 아래에 `export PATH = $PATH:/home/pi/hadoop` 를 써주면 된다.<br>
이 때 경로 앞에 `$PATH: ` 를 써주었는데, 이는 기존에 PATH변수에 저장되어 있던 설정 값들을 의미한다. 따라서 새로 추가하고자 하는 값은, 값이 나열되어 있는 목록에서 맨 뒤에 자리잡게 하겠다는 의미이다. 정리하자면 아래와 같다.

```
$ echo $PATH
> /usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin 
$ export PATH = $PATH:/home/pi/hadoop
> /usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/home/pi/hadoop
```

이제 PATH에 새로운 경로가 추가 됐으므로 이 디렉토리 안에 있는 **실행파일**을 이 디렉토리로 이동하지 않고 아무 위치에서나 실행 할 수 있는 준비가 되었다.<br>


환경변수 수정을 끝냈으면 .bashrc 를 저장한 후 실제로 이 내용을 시스템에 저장해야 한다.<br>
적용하는 방법은 

```
source .bashrc 
```
와 같이 source 명령어를 사용하면 된다. 잘 적용됐는지 확인하기 위해선 echo $PATH로 보면 된다.


패키지 매니저(apt-get, homebrew, yum 등) 를 사용하지 않고 프로그램을 설치하다 보면 환경변수를 설정해야 하는 경우가 빈번하다. (source 컴파일로 설치하거나 실행 파일(binary)만 있는 프로그램만 다운받은 등..) <br>이럴 때는 어디서든 프로그램을 실행하기 위해선 환경변수 등록이 필수이니 잘 알아둘 필요가 있다.
<br><br>


###참조URL
http://cafe.naver.com/pipc/14139 <br>
http://inhack.org/wordpress/?p=2968 <br>
https://kldp.org/node/112128 <br>
https://ko.wikipedia.org/wiki/%ED%99%98%EA%B2%BD_%EB%B3%80%EC%88%98 <br>
http://tip.daum.net/question/2624224 <br>
