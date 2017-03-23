# Atom을 Python 개발 툴로 사용하기 (OS x)

## Atom 터미널에서 실행하기
Django프로젝트를 진행할 때 [Atom](https://atom.io/)이라는 IDE를 활용하기로 하였다. 가상환경 안에서의 원활한 작업을 위하여 터미널에서 해당 디렉토리나 특정 파일을 텍스트 에디터로 바로 열고자 할 때 사용할 수 있는 방법이다.

### 1

우선, Atom 메뉴를 클릭하여 `Install Shell Commands` 를 설치한다.<br>
![Install Shell Commands](https://68.media.tumblr.com/b9ad325b57bba41084ac7a4c777ac5d7/tumblr_okby5mWwOV1v80c66o2_400.png)<br><br>

설치하기 전엔 이렇게 터미널에서 인식이 되지 않는다.<br>
![Error](https://68.media.tumblr.com/015dc5fc1e771e74db8b06b3778b8368/tumblr_okby5mWwOV1v80c66o1_400.png)

설치 후엔 다음과 같은 명령어를 쓰면 터미널에서도 atom을 열 수 있다.

```shell
$ atom mytest.py #아톰 에디터를 통해 해당 파일을 오픈
$ atom pythonText_directory #아톰 에디터를 통해 해당 디렉토리를 오픈
$ atom . #"."은 현재 폴더를 프로젝트로 오픈한다는 의미
```
<br>

## Atom을 파이썬 IDE로 활용하기
**`script`와 `autocomplete-python` 설치**

Atom의 기본 설정으로는 코드를 실행할 수 없기 때문에 패키지에서 `script`를 설치하여 코드를 실행할 수 있도록 한다.<br>
또한, 파이썬의 자동완성을 위해 `autocomplete-python` 패키지를 설치하면 도움이 된다.


### 참고URL<br>
[https://xho95.github.io/editor/atom/markdown/python/2016/09/27/Using-Atom-Editor.html#fn:stackoverflow](https://xho95.github.io/editor/atom/markdown/python/2016/09/27/Using-Atom-Editor.html#fn:stackoverflow)
[https://blog.chann.kr/how-to-use-python3-in-atom/](https://blog.chann.kr/how-to-use-python3-in-atom/)
[http://junho85.pe.kr/525](http://junho85.pe.kr/525)
