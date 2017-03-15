# Daemon

> 사전적인 뜻으로는 유령, 악마, 혹은 신화 속의 반신반인의 존재. 우리 **눈에 보이지 않는 곳**(background작업 특징) 에<br>**항상 존재** (항상 실행되고 있다는 특징) 하고 있음을 상징하기 위해 네이밍 했다고 추정된다..!

상주 프로그램(Resident Program)이라고도 불리우며, 항상 실행된다는 특성을 가지고 있다. 

컴퓨터 시스템 운영에 관련된 작업을 후선(background) 상태로 동작하면서 실행하는 프로그램. 처리해야 할 작업 조건이 발생하면 자동으로 작동하여 필요한 작업을 실행한다.

우리가 흔히 접하는 실행프로그램들(ls, mkdir, rm …) 은 daemon이 아니다. 이들은 daemon 프로그램들과는 달리 필요할 때 키고 필요 없을 땐 끄곤 하기 때문이다.

Daemon의 대표적인 사례로는 클라이언트의 요청을 항상 받을 준비가 되어있어야 하는 **웹서버**를 들 수 있다. Daemon프로그램은 주로 start, stop명령어를 통해 끄고 킬 수 있다.



# Cron

유닉스 계열 컴퓨터 운영체제 기반의 "잡 스케쥴러"이다. 원하는 작업을 고정된 시간, 날짜, 간격에 주기적으로 실행할 수 있도록 스케줄링해야 할 때 Cron을 통해 할 수 있다.

Cron은 셸 명령어들이 주어진 일정에 주기적으로 실행하도록 규정해놓은 crontab (cron table) 파일에 의해 구동된다.



### 옵션

```shell
$ crontab [옵션]
```

-l : 현재 crontab에 작성된 내용들을 출력<br> -e : crontab내용을 작성 및 수정 <br> -r : crontab내용을 삭제<br>-u : root가 해당 사용자의 crontab파일을 다룰 때 사용



### 문법

Crontab 파일의 문법은 다음과 같다.<br>

![https://68.media.tumblr.com/3dab35ceac996169eb24a88bf91199ef/tumblr_oks1qmawsn1v80c66o1_400.png](https://68.media.tumblr.com/3dab35ceac996169eb24a88bf91199ef/tumblr_oks1qmawsn1v80c66o1_400.png)

```shell
* * * * * /root/every_1min.sh
# 매 1분마다 /root/every_1min.sh 를 수행 (하루에 1440회)
```


```shell
15,45 * * * * /root/every_30min.sh
# 매시 15분, 45분에 /root/every_30min.sh 를 수행 (하루에 48회)
```


```shell
*/10 * * * * /root/every_10min.sh
# 10분마다 /root/every_10min.sh 를 수행 (하루에 144회)
```


```shell
0 2 * * * /root/backup.sh
# 매일 02:00에/root/backup.sh 를 수행 (하루에 1회)
```


```shell
30 */6 * * * /root/every_6hours.sh
# 매 6시간마다 수행(00:30, 06:30, 12:30, 18:30)
```


```shell
30 1-23/6 * * * /root/every_6hours.sh
# 1시부터 매 6시간마다 수행(01:30, 07:30, 13:30, 19:30)
```


```shell
0 8 * * 1-5 /root/weekday.sh
# 평일(월요일~금요일) 08:00
```


```shell
0 8 * * 0,6 /root/weekend.sh
# 주말(일요일, 토요일) 08:00
```



### 예시

crontab파일은 `crontab -e` 명령어를 통하여  수정할 수 있다. (처음으로 해당 명령어를 실행할 때는 파일 편집을 할 수 있는 편집기를 선택할 수 있게 한다고 했는데…일단 나는 자동으로 vim 편집기로 열렸다.)

`crontab -e` 를 통해 crontab 파일을 열어 주기적으로 실행하고자 하는 명령을 입력한다. 나는 다음과 같은 명령을 입력하였다.

![https://68.media.tumblr.com/bc1ce3e28e0948c5b3e3cc6b681e935d/tumblr_oks1ptextW1v80c66o1_540.png](https://68.media.tumblr.com/bc1ce3e28e0948c5b3e3cc6b681e935d/tumblr_oks1ptextW1v80c66o1_540.png)

작성한 명령을 해석하자면 다음과 같다. 이 명령어 전반의 문법에 대한 자세한 설명은 [여기로](https://github.com/Shinye/TIL/blob/master/Linux/Linux_IORedirection.md)

```shell
$ */1 * * * * date >> date.log 2> &1
# 1분에 한 번씩
# 명령어 date를 실행시킨 결과값(Standard Output)을 date.log에 저장하며
# 만약 명령어 date 실행 시 오류(Standard Error)가 나도(2>)
# 그대로 표준출력 로그(date.log)에 기록하게 한다. (&1)
# Output에서 숫자 1은 표준출력, 숫자 2는 표준오류를 의미한다.
# 만약 &1 대신 1을 입력하면 1이라는 이름의 파일이 만들어져 그 파일에 에러 메세지가 저장되게 되므로 숫자 앞에 &를 붙여주자.
```

![https://68.media.tumblr.com/33417ff9b4d6b5287c208cd2326fe9ca/tumblr_oks1ptextW1v80c66o2_500.png](https://68.media.tumblr.com/33417ff9b4d6b5287c208cd2326fe9ca/tumblr_oks1ptextW1v80c66o2_500.png)

crontab 파일을 저장하고 편집기를 나오면 `crontab: installing new crontab` 이라는 메세지가 뜬다.<br> 정상적으로 명령어가 입력되었는지 확인하고 싶다면 `crontab -l` 을 입력하면 내가 입력한 cron명령어 목록들이 출력된다.

`cat date.log` 명령어를 통해 확인해본 결과 1분에 한 번씩 `date` 명령어의 결과값이 정상적으로 출력되고 있음을 알 수 있다.



### 참고 URL

[http://zetawiki.com/wiki/%EB%A6%AC%EB%88%85%EC%8A%A4_%EB%B0%98%EB%B3%B5_%EC%98%88%EC%95%BD%EC%9E%91%EC%97%85_cron,_crond,_crontab](http://zetawiki.com/wiki/%EB%A6%AC%EB%88%85%EC%8A%A4_%EB%B0%98%EB%B3%B5_%EC%98%88%EC%95%BD%EC%9E%91%EC%97%85_cron,_crond,_crontab)