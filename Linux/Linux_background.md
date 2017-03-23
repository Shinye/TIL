# Linux 백그라운드 실행



여러개의 일을 하나의 화면에서 할 수 있는 멀티태스킹은 리눅스/유닉스 계열에서도 가능하다.<br>
=> `Background와 Foreground의 전환 작업` 이 가능.<br><br>
- `fg` : foreground의 약자. 아까 작업하던 프로그램이 다시 켜진다.<br>
- `Ctrl + z` : 현재 실행중인 프로그램을 백그라운드로 보내는 단축키. 이 기능을 실행하면 현재 실행중인 프로그램이 일시 정지 된다.<br>
- `jobs` : 백그라운드 작업 목록을 보여준다.

스크린 샷 예시 )<br>
![https://68.media.tumblr.com/07b9c2a6a5fd48c3ef0da79704eb8efb/tumblr_okjowgVRq61v80c66o1_1280.png](https://68.media.tumblr.com/07b9c2a6a5fd48c3ef0da79704eb8efb/tumblr_okjowgVRq61v80c66o1_1280.png)
![https://68.media.tumblr.com/424066dc4236441184ce674c4272f82d/tumblr_okjoslmbVp1v80c66o2_1280.png](https://68.media.tumblr.com/424066dc4236441184ce674c4272f82d/tumblr_okjoslmbVp1v80c66o2_1280.png)

vim 편집기를 통해 임의의 파일을 만든다. <br>파일을 저장한 후 파일의 저장이 원활하게 되었는지 확인하기 위해 vim 프로세스를 background로 보내고자 `ctrl+z` 를 누른다.<br>

![https://68.media.tumblr.com/3a61e36d99c7093865ce0c07e70cb2b4/tumblr_okjoslmbVp1v80c66o3_1280.png](https://68.media.tumblr.com/3a61e36d99c7093865ce0c07e70cb2b4/tumblr_okjoslmbVp1v80c66o3_1280.png)
<br>vim편집기를 백그라운드에 둔 후의 터미널이다.<br>
ls 명령어를 쳐보면 방금 저장한 test.html이 정상적으로 저장됨을 알 수 있다.(그 부분 캡처를 깜빡...ㅠㅠ)<br>
여기서 `fg`를 치면 백그라운드로 보내두었던 프로그램을 다시 foreground로 보냄으로써 기존의 vim편집기로 돌아간다.<br>

![https://68.media.tumblr.com/3119454422f9df0b4965bf36c0e3beb4/tumblr_okjoslmbVp1v80c66o8_1280.jpg](https://68.media.tumblr.com/3119454422f9df0b4965bf36c0e3beb4/tumblr_okjoslmbVp1v80c66o8_1280.jpg)

여러 프로세스들을 백그라운드로 보냈을 때의 경우이다.<br>
- 더하기 : fg 명령어를 입력할 때, background에 있던게 foreground로 가는 거<br>
- 빼기 : fg 명령어를 입력할 때, 더하기에 해당되는 프로세스가 종료되면 실행 됨<br>
- 아무것도 없음 : 세번째 백그라운드 프로세스부터 해당. 빼기 프로세스가 종료되면 나머지는 숫자 순서대로 실행된다.<br>

원하는 프로세스만을 선택적으로 작업하고 싶은 경우는 프로세스 목록 앞의 숫자를 활용한다.<br>
- jobs중 원하는 프로세스를 실행하고 싶다 : 2번 프로세스의 실행을 원할 경우, `fg %2` <br>
- jobs중 원하는 프로세스를 종료하고 싶다 : 4번 프로세스의 종료를 원하는 경우, `kill %4`<br>
- 보다 강력한 삭제 : kill명령어의 옵션 -9를 쓴다. `kill -9 %4` <br>

&가 명령어 뒤에 붙으면 명령어가 실행될 때 백그라운드로 실행된다.

```
ls -alR / > result.txt 2> error.log &
```


### KILL 명령어에 관하여
**1. kill의 기능<br>**
The kill utility **sends a signal to the processes** specified by the pid operand(피연산자). Only the super-user may send signals to other users' processes.<br>
 `현재 수행 중인 프로세스에게 시그널(신호)를 보내는 것` 이다. 단순히 실행 중인 프로세스를 종료시키는 것이라는 것은 정답이 아니다. 이는 kill 명령어 기능의 일부일 뿐이다.

**2. 문법<br>**

```
kill [-signalID] PID
kill  -l
```


**3. 주요 옵션**<br>
터미널에서 `man kill` 을 통해 본 설명에 의하면
![https://68.media.tumblr.com/a3010932af33900317432733a8c906b4/tumblr_okjs2n2k5N1v80c66o1_500.png](https://68.media.tumblr.com/a3010932af33900317432733a8c906b4/tumblr_okjs2n2k5N1v80c66o1_500.png)<br>
다음과 같은 옵션들이 있다.<br> 디폴트로 사용되는 kill 명령어의 시그널 넘버는 15번 (TERM - software termination(종료) signal) 이다. 
<br>

**3-1. kill -9와 kill -15의 차이** ...더 공부해보기!<br>
요약하자면 15는 정상종료, 9는 강제종료 이다. 프로세스를 terminating(15)하는 것과 kill(9) 하는 것은 다르다.<br><br>
**(1) -15**<br>
- TERM 시그널 (기본 옵션)<br>
- 자신이 하던 작업을 모두 안전하게 종료하는 절차를 밟는다.<br>
- 메모리상에 있는 데이터와 각종 설정/환경 파일을 안전하게 저장한 후 프로세스를 종료한다.<br>

```
# kill PID 
# kill -15 PID
```

**(2) -9**
<br>
- 리눅스 커널이 프로세스를 강제 종료한다.<br>
- 작업중인 모든 데이터를 저장하지 않고 프로세스를 종료하기 때문에<br>
- 저장되지 않은 데이터는 소멸된다.<br>

```
# kill -9 PID
```

<br><br>참고 URL<br>
[http://rerethink.tistory.com/entry/%EB%A6%AC%EB%88%85%EC%8A%A4-kill](http://rerethink.tistory.com/entry/%EB%A6%AC%EB%88%85%EC%8A%A4-kill)<br>
[http://blog.naver.com/eunjiban/220694919686](http://blog.naver.com/eunjiban/220694919686)