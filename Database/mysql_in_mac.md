# 맥에서 MySQL 설치 후 환경설정하기

[http://dev.mysql.com/downloads/mysql/](http://dev.mysql.com/downloads/mysql/) 에 접속해서 다운받는 방법이 있지만, 이렇게 다운받으면 환경변수 설정 등 비교적 번거로움이 있어 homebrew를 통한 설치를 하고자 한다. (공식 홈페이지를 통한 자세한 설치 방법은 http://palpit.tistory.com/871 여기에 잘 설명되어 있다.)



## Homebrew를 통한 MySQL 설치

1. Homebrew 설치 (안되어있다면!)

2. mysql 설치 `$ brew install mysql`<br>혹시 이전에 설치했나 궁금하다면 `brew info mysql` 명령어를 치면 된다. 

   ![https://drive.google.com/uc?id=0B3Or0Wv2t1xwQmJuMUM1d0l4clE](https://drive.google.com/uc?id=0B3Or0Wv2t1xwQmJuMUM1d0l4clE)

   이전에 HomeBrew로 설치한적이 있다면 위와 같은 정보를 확인할수있다. mysql을 미리 띄워놓지않고 필요할때만 서버를 띄워서 개발하는 편이라면 아래 후술 할 `mysql.server start` 명령어를 사용하면 좋다. 아래에도 이어서 설명이 나오겠지만 HomeBrew의 강점중에 하나는 /usr/local/Cellar 폴더에 패키지를 설치한후 심볼릭 링크를 알아서 만들어주기 때문에 어디서든 명령어만 입력하면 된다. 즉 설치한 경로를 늘 일일이 다 입력하지 않아도 되는 장점이 있다.

3. MySQL 시작 : `$ mysql.server start`

4. root 비밀번호 설정 : `$ mysql_secure_installation`

   - `Would you like to setup VALIDATE PASSWORD plugin?` : 비밀번호 가이드. 복잡한 비밀번호를 사용하도록 제한하고, 비밀번호를 보안성 높게 설정하도록 가이드라인을 주는 플러그인을 사용하려면 `yes`, 그냥 쓰던 비밀번호 제한받지 않고 쓰고 싶다면 `no`. (근데 본인이 원래 비밀번호 복잡하게 만드는 사람이라면 굳이 yes안해도 되는듯...)
   - `Remove anonymous users?` : 익명사용자 삭제할지/계속 사용할지 여부. `no` 하면 `$ mysql -uroot`가 아니라 `$ mysql`만으로도 접속 가능. `yes`하면 `-u` 옵션 필수.
   - `Disallow root login remotely?` : localhost외에 다른 ip에서 root 아이디로 원격접속 가능하게 할지. `yes`하면 원격 접속 불가.
   - `Remove test database and access to it?` : mysql에 기본적으로 설정된 test 디비 삭제 여부.
   - `Reload privilege tables now?` : 하나라도 권한 변경을 했다면 `yes` 해서 하는 게 정신건강에 좋을 것입니다.

5. charset 설정 : `$ mysql -uroot -p`로 로그인하고, `> status;`로 charset 확인.

   - 기본적으로 charset 4개가 모두 utf8이어서 그대로 두면 됨!
   - 혹시나 latin등 다른 값이 있다면 utf8로 바꿔주기.

6. 데몬 실행하고 싶다면 `$ brew services start mysql` ([참고](https://robots.thoughtbot.com/starting-and-stopping-background-services-with-homebrew))

   - 로그인시 데몬 자동 실행 (To have launchd start mysql at login): `$ ln -sfv/usr/local/opt/mysql/*.plist ~/Library/LaunchAgents`

7. 고맙게도 brew로 설치한다면 환경변수 설정은 필요없다!



## MySQL 시작하기

서버를 실행했다면 이제 mysql 서버에 접속해보자. 보통은 커맨드라인 어디에서든 mysql로 로그인하면 된다. 하지만 그냥 로그인하면 권한이 없는 경우 많다. 그래서 일단 root로 로그인하자. 

```shell
$ mysql -uroot -p
```



### 사용할 DB 만들기

이제 개발에 필요한 혹은 사용할 데이터베이스를 만들어보자.

```mysql
mysql> create database testdb;
Query OK, 1 row affected (0.00 sec)
```

그리고 꼭 캐릭터셋을 확인해야한다. mysql을 설치하고 따로 캐릭터셋(charset)을 따로 설정하지 않았다면 *latin1* 으로 설정되는데 latin1 캐릭터셋을 쓰면 한글은 당연히 안되고 몇몇 특수문자를 사용할경우 DB에서 입력이 안되는 경우가 허다하다. 그래서 반드시 utf-8로 설정되어 있는지 확인해야한다. 확인하는 방법은 다음과 같다.

```mysql
mysql> show create database testdb;
+----------+-----------------------------------------------------------------+
| Database | Create Database                                                 |
+----------+-----------------------------------------------------------------+
| testdb   | CREATE DATABASE `testdb` /*!40100 DEFAULT CHARACTER SET utf8 */ |
+----------+-----------------------------------------------------------------+
1 row in set (0.00 sec)
```



### DB 생성 및 생성된 DB 사용자 추가하기

권한을 추가하는 방법은 여러가지가 있지만 그냥 쉬운 grant 명령을 이용하자.

```mysql
// localhost로 접속만 허용하는 dev 유저 계정 생성
mysql> grant all privileges on testdb.* to dev@localhost identified by 'password123';

// 원격 접속도 허용하는 devguest 유저 계정 생성 
mysql> grant all privileges on testdb.* to devguest@'%' identified by 'password123';
```



dev라는 계정을 만들고 이 계정으로 사용할 testdb도 지정해줬으므로 이제 root가 아닌 dev 계정으로 로그인해서 사용할수있는 DB가 보이는지 확인해보자.

```mysql
$> mysql -u dev -p
Enter password: (앞에서 지정한 패스워드 입력)
... 중략 ...
Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| testdb             |
+--------------------+
3 rows in set (0.00 sec)
```

여기 까지 mysql로 개발할때 필요한 기본적인 과정이다.



### 참고 URL

[맥에서 mysql 설치 후 환경설정하기](https://github.com/helloheesu/SecretlyGreatly/wiki/%EB%A7%A5%EC%97%90%EC%84%9C-mysql-%EC%84%A4%EC%B9%98-%ED%9B%84-%ED%99%98%EA%B2%BD%EC%84%A4%EC%A0%95%ED%95%98%EA%B8%B0) <br>[Mac에서 MySQL 설치와 실행 그리고 몇가지 유의사항](http://miconblog.com/archives/2014/11/mac%EC%97%90%EC%84%9C-mysql-%EC%84%A4%EC%B9%98%EC%99%80-%EC%8B%A4%ED%96%89-%EA%B7%B8%EB%A6%AC%EA%B3%A0-%EB%AA%87%EA%B0%80%EC%A7%80-%EC%9C%A0%EC%9D%98%EC%82%AC%ED%95%AD/)