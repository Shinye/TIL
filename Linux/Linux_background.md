#Linux 백그라운드 실행



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
- 보다 강력한 삭제  : kill -9 %4 <br>

&가 명령어 뒤에 붙으면 명령어가 실행될 때 백그라운드로 실행된다.

```
ls -alR / > result.txt 2> error.log &
```
