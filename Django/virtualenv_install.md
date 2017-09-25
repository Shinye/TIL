# VirtualEnv 설치 (OS X)

(3년 전 윈도우 OS를 쓰던 시절 처음 파이썬을 공부해보고자 마음을 먹었던 때, 가상환경 설치가 너무 어려워 일주일 가까이 헤맸었던 기억이 난다...결국 헤맴의 원인은 환경변수 오타였고 허탈함과 함께 모든 전의를 상실했던 아련한 추억이..ㅎㅎㅎㅜ.ㅜ)
<br><br>
Python을 주력 언어로 개발을 하다 보면 다양한 라이브러리(패키지)들을 사용하게 되는데, 이 때 파이썬 자체는 물론이고 라이브러리들(Django 등)의 버전 충돌 등의 이슈들을 방지하기 위해 가상환경이 필요하다.<br><br>
예를 들어, A프로젝트는 Python 2.7버전과 pip로 install한 Django1.6버전을 사용하고 / B프로젝트는 Python3.0과 Django1.10버전을 사용한다고 가정하자. 가상환경 없이 root에 B프로젝트를 위해 파이썬과 장고 버전을 업그레이드 했다면 A프로젝트를 다시 수정 할 때 버전이 다름으로 인해 여러 충돌이 발생할 것이다.<br>
 이처럼 각 프로젝트별로 독립된 개발환경을 제공하는 것을 가능하게 해주는 것이 바로 가상환경(virtual environment - virtualenv) 프로그램 이다.
<br>

OS X 기준으로 virtualenv를 다운받기 위해선 사전에 작업해주어야 하는 것들이 있다.<br>
### 1. Homebrew 설치 <br>
 OS X(맥)을 쓸 때 가장 좋은 점은 루비나 파이썬 등이 미리 OS에 포함이 되어 있다는 것이다. 아쉬운 점이라면 최신 버전은 아니라는 것. 이처럼 맥에서는 기본적으로 파이썬이 설치가 되어 있다. 하지만 디폴트로 설치되어 있는 파이썬 버전이 구버전일 상황이 많기 때문에 파이썬을 새로 까는 것이 좋다. 따라서 파이썬을 설치하기 위해 Homebrew가 필요하다.<br>

 **Homebrew란?**<br>
 Homebrew란 맥에서 사용되는 **패키지 매니저**이다. 여기서 패키지란 흔히 프로그램/어플리케이션을 지칭하고, 컴퓨터를 사용한다는 것은 이러한 패키지들이 가지고 있는 기능성을 이용하여 다양한 처리를 하는 것이다. (리눅스에서 기본적으로 제공되는 ls, mkdir, cd 등의 명령어 역시 프로그램이다)<br>
오늘날의 패키지 매니저는 스마트폰의 **구글 플레이 스토어, 앱 스토어** 와 같은 역할을 한다고 생각하면 이해가 쉽다. <br>필요한 프로그램 찾을 수 있고, 다운로드 받아서 설치도 삭제도 해주며, 업데이트 등 기타 관리 작업들도 가능하다는 점에서 플레이스토어의 기능과 유사하다고 볼 수 있다. 그 외 리눅스에서 사용되는 패키지 매니저는 apt와 yum이 있다.<br>

**Homebrew 설치** ([http://brew.sh/index_ko.html](http://brew.sh/index_ko.html))
<br>터미널을 켜 다음의 코드를 붙여넣기 한다.
```shell
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```
<br>
### 2. Python, pip 설치
파이썬은 다음과 같이 설치할 수 있다.<br>

```shell
$ brew install python
#python3의 경우는 brew install python3 을 작성해주면 된다. 
```

**pip란?**<br>
파이썬 패키지 매니저. 파이썬으로 작성 된 패키지(라이브러리) 를 관리하는 프로그램이다. 라이브러리를 설치할 때, 설치하고자 하는 라이브러리가 의존하는 다른 모든 라이브러리들의 설치까지 포함시켜주며, 설치된 라이브러리의 버전을 주기적으로 관리하는 등의 역할을 담당한다.<br><br>
pip설치는 다음과 같이 할 수 있다.

```shell
$ sudo easy_install pip
```

**이 때 쓰인 easy_install 은 뭘까요?** <br>
pip와 동일한 기능을 하는 파이썬 패키지 매니저.. easy_install 의 대체품이라 생각하면 쉽다. pip가 easy _ install 에 비해 개선된 패키지 매니저이기 때문에 easy _ install을 통해 pip를 설치한 후엔 pip를 사용하는 것을 권장한다. (_를 붙여쓰면 자꾸 이텔릭체로 변환이 되서ㅠㅠ;; 당연히 붙여써야 합니다!! 표기가 이상한 점 죄송합니다..)

pip가 올바르게 설치되어 있는지 확인하기 위해선 다음과 같이 pip의 버전을 확인해볼 수 있다.

```shell
$ pip -V
# 대문자 V 이다.
# python3의 pip의 경우 pip3 -V 라고 작성하면 된다.
```


### 3. virtualenv / virtualenvwrapper 설치
아래의 명령어로 간단하게 두 패키지를 설치할 수 있다.

```shell
$ sudo pip install virtualenv virtualenvwrapper
```

**virtualenvwrapper 란?**
>virtualenvwrapper is a set of extensions to Ian Bicking’s virtualenv tool. The extensions include wrappers for creating and deleting virtual environments and otherwise managing your development workflow, making it easier to work on more than one project at a time without introducing conflicts in their dependencies.
>>**Features**<br>
1. Organizes all of your virtual environments in one place.<br>
2. Wrappers for creating, copying and deleting environments, including user-configurable hooks.<br>
3. Use a single command to switch between environments.<br>
4. Tab completion for commands that take a virtual environment as argument.<br>
5. User-configurable hooks for all operations.<br>
6. Plugin system for more creating sharable extensions.<br>

virtualenvwrapper는 virtualenv의 사용을 보다 편리하게 해주는 도구의 집합이다. <br>가상환경을 생성, 삭제할 수 있으며 한 가상환경에서 다른 가상환경으로 명령어(workon [가상환경 이름])를 통해 넘어갈 수 있는 등의 기능을 제공한다.

### 3-1. virtualenvwrapper 설정하기
VirtualEnv를 사용하기 위해서는 `source`[^source] 를 이용해 가상환경에 진입한다. 그러나, 이 진입 방법은 가상환경이 설치된 위치로 이동해야되는 것 뿐 아니라 가상환경이 어느 폴더에 있는지 일일이 사용자가 기억해야 하는 단점이 있다. 이를 보완하기 위해 virtualenvwrapper를 사용한다.<br>

또한, VirtualenvWrapper를 사용할 경우 **터미널이 현재 위치한 경로와 관계없이** 가상환경을 활성화할 수 있다는 장점이 있다. <br>
VirtualenvWrapper는 `.bashrc` 나 `.zshrc` 에 약간의 설정과정을 거쳐야 한다. 본인의 터미널 환경이 bash이냐 zsh이냐에 따라 알맞는 것을 선택하면 된다. <br>(나는 zsh를 쓰는데 그걸 잊고 무작정 .bashrc에 가서 고치려고 했었다...바부-_-;;)

우선, 홈 디렉토리로 이동한다.<br>

`````shell
$ cd ~
`````

만든 가상환경이 들어갈 폴더 `.virtualenv` 를 만든다.<br>

```shell
$ mkdir ~/.virtualenvs
```

그리고 홈 디렉토리의 `.bashrc`나 `.zshrc`의 파일 제일 마지막에 아래 코드를 복사해 붙여넣어준다. (파일이 없다면 만들어 사용하시면 된다.)

```shell
# python virtualenv settings
export WORKON_HOME=~/.virtualenvs
export VIRTUALENVWRAPPER_PYTHON='$(command \which python3)' # Usage of python3!!
source /usr/local/bin/virtualenvwrapper.sh
```

저장하고 나온 후 터미널을 종료후 새로 켜주면, VirtualenvWrapper의 명령어들을 사용할 수 있다.
<br>만약 /usr/local/bin/virtualenvwrapper.sh파일이 존재하지 않는다면, 
다음 명령어로 virtualenvwrapper.sh파일을 찾아서 위 코드를 바꿔 사용한다. [^find]

```shell
$ find /usr -name virtualenvwrapper.sh 
```

### 3-2. virtualenvwrapper 기본 명령어들

1-1) 가상환경 만들기

```shell
$ mkvirtualenv 가상환경이름
# 예시
# mkvirtualenv test_env1
```
mkvirtualenv 명령어를 사용할 경우 홈 디렉토리의 `.virtualenvs` 폴더 안에 가상환경이름을 가진 폴더`test_env1` 가 생긴다.

1-2) Python2.X가 디폴트인 환경에서 `Python3.X` 버전의 가상환경 만들기

```shell
# 파이썬2가 기본인 환경에서 파이썬3을 기본으로 하는 환경을 만들고 싶은 경우
$ virtualenv -p python3 [env_name] 
```



2) 가상환경 지우기

```shell
$ rmvirtualenv 가상환경이름
# 예시
# rmvirtualenv test_env1
```

rmvirtualenv 명령어를 사용할 경우 mkvirtualenv로 만든 가상환경을 지워준다.

3) 가상환경 진입하기 + 가상환경 목록 보기

```shell
$ workon 가상환경이름
# 가상환경으로 진입시 앞에 (가상환경이름)이 붙는다.
(가상환경이름) $
# 예시
# $ workon test_env3
# (test_env3) $
```
workon명령어를 통해 mkvirtualenv로 만든 가상환경으로 진입할 수 있다.<br>
workon명령어를 가상환경이름 없이 단순하게 칠 경우, 현재 만들어져있는 가상환경의 전체 목록을 불러온다.

```shell
$ workon
test_env3 test_env5
```

4) 다른 가상환경으로 전환하기

```shell
(test_env3) $workon test_env5
(test_env5) $
```

`workon [변경하고자 하는 가상환경 이름]` 을 치면 다른 가상환경으로 전환이 가능하다.

5) 가상환경 빠져나오기

```shell
(가상환경이름) $ deactivate
$
# 예시
# (test_env3) $ deactivate
# $
```

<br><br>

[^source]: bash 내부 명령어로, 스크립트 파일을 수정한 후에 수정된 값을 바로 적용하기 위해 사용하는 명령어이다. source 뒤의 파일을 읽어 실행한다. source 대신 그 자리에 '.' 을 작성하여 사용할수도 있다.

[^find]: **find 명령어** : 디스크에 저장된 각종 파일/디렉토리를 검색할 수 있다. 위의 코드는 usr 디렉토리에서 virtualwrapper.sh 라는 이름의 파일을 찾는 명령이란 뜻이다. 자세한 설명은 [여기](http://geundi.tistory.com/37)서 확인.<br>`find [찾을 디렉토리 경로] [찾기 옵션]` 

<br><br>
**참고 url**<br>
https://pypi.python.org/pypi/virtualenvwrapper<br>
http://blog.naver.com/ez_/140138625021<br>
http://intersnipe.blogspot.kr/2015/01/mac-django-virtualenv-virtualenvwrapper.html
https://beomi.github.io/2016/12/27/HowToSetup-Virtualenv-VirtualenvWrapper.html
http://hackersstudy.tistory.com/43<br>http://ulismoon.tistory.com/2