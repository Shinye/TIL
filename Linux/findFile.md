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
여기서 잠깐, **환경변수란?**<br>
OS레벨에서 "자주 사용하는" 또는 "필요한" 변수들을 미리 선언해 놓는 것이다.<br>
본인 컴퓨터의 환경변수 목록을 보고 싶다면 `printenv`,`export` 등의 명령어를 쓰면 된다.<br>
특정 환경변수에 대해서 확인하고 싶다면 `echo $환경변수명 을 쓰면 된다.`<br>

```
$ echo $PATH
/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin 
# 리눅스/유닉스 환경에선 디렉토리 사이의 구분을 ;가 아닌 :로 한다.
```
~수정중~

export 변수=값  # Bourne, bash, 그리고 다른 셸에서 쓰임









