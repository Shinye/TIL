#프로세스
![https://68.media.tumblr.com/449c3ea2351d4bf0c23f593ea4b7e7dc/tumblr_ok4bzwdlCK1v80c66o1_540.jpg](https://68.media.tumblr.com/449c3ea2351d4bf0c23f593ea4b7e7dc/tumblr_ok4bzwdlCK1v80c66o1_540.jpg)

1. mkdir, tm, top 등의 각 명령어들은 각각 하나의 프로그램이다.<br> 이들은 /bin, /sbin 디렉토리에 **파일의 형태**로, 하드디스크에 저장된다.
2. `하드디스크(Storage)`에 어장된 프로그램이 실행되면 `메모리`에 적재된다.
3. 이 적재된 프로그램은 `CPU(Proccessor)`에 의해 처리되고 이것을 `프로세스` 라고 한다.

--


###명령어 ps
- 명령어 ps는 현재 실행 중인 process들의 목록을 보여준다.<br>
- ps aux : 현재 실행중인 프로세스 뿐만 아니라 백그라운드 프로세스 까지도 보여준다.<br>
예) ps aux | grep apache : 현재 실행중인 프로세스 및 백그라운드 프로세스 목록 중에서, (파이프라인 |를 통해 이어짐) apache 라는 단어가 있는 프로세스만을 골라 보여준다.<br>
- sudo kill [pidNum] : 종료하고 싶은 프로세스가 있을 때, `sudo kill` 이라는 명령어 뒤에 삭제하고자 하는 프로세스의 고유번호(pid) 번호를 입력하여 프로세스를 종료시킨다.