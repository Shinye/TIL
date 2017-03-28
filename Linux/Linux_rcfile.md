# RCfile이란?

리눅스/유닉스 환경에서 작업을 하다 보면 `.bashrc` 혹은 `.zshrc` 에 무언가를 작성 후 저장하라는 튜토리얼을 많이 보곤 한다. 여기서 파일명 뒤에 붙는 rc가 무엇인지 궁금해서 찾아보았다.

[http://unix.stackexchange.com/questions/3467/what-does-rc-in-bashrc-stand-for](http://unix.stackexchange.com/questions/3467/what-does-rc-in-bashrc-stand-for) 에 달린 답변에 의하면 다음과 같다.

> [Unix: from runcom files on the CTSS system 1962-63, via the startup script /etc/rc] 
>
> Script file containing startup instructions for an application program (or an entire operating system), usually a text file containing commands of the sort that might have been invoked manually once the system was running but are to be executed automatically each time the system starts up.

원문에 쓰여진 것과 같이, 프로그램 혹은 OS를 실행할 때 자동으로 함께 실행되어야 하는 기능들을 담은 파일이라고 볼 수 있다. 이 때 rc는 runcom의 약자라고 쓰여져있는데, runcom은 run commands 라고 한다.

하지만 이런 의견도 달렸다.

> I tend to see it as more of a historical name than meaningful at this point. Many uses of "rc" aren't really "run commands" anymore, unless you want to be pedantic and call assignment a command; often, a program's rc file is just config parameter values. Completely correct answer though :) 

현재 rc파일의 사용은 명령어의 집합이라기 보다는 해당 프로그램에 필요한 변수와 그 값들의 집합이라고 보는 것이 맞다는 말이였다. 그래서 내 .zshrc파일을 까보았다.

![https://68.media.tumblr.com/2808f76fcd6784c0daa3d96457acbda7/tumblr_onhihiI92s1w8w3y8o1_1280.png](https://68.media.tumblr.com/2808f76fcd6784c0daa3d96457acbda7/tumblr_onhihiI92s1w8w3y8o1_1280.png)

확인해본 결과 변수에 값을 선언한 줄도 있고 source 명령어를 통해 .sh파일을 실행하는 명령어도 존재한다. 따라서 둘 다 맞는 것 같은 것으로…당장의 궁금증은 어느정도 해결됐지만 좀 더 구체적으로 찾아보고 싶다. 주말에 다시 찾아보고 수정해야지.