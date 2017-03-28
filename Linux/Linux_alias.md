# Alias에 대하여

`alias` 란, 리눅스 bash/zsh 에서 단축 별칭을 지정 및 조회 할 수 있는 명령어이다.

**alias 설정 조회**

```shell
alias
```

**alias 추가**

```shell
alias 단축명='실행할명령어'
```

![https://drive.google.com/uc?id=0B3Or0Wv2t1xwQTdOU1ZwOVRTTVE](https://drive.google.com/uc?id=0B3Or0Wv2t1xwQTdOU1ZwOVRTTVE)

**unalias** : 리눅스 bash/zsh 단축 별칭 해제 명령어

```shell
unalias 단축이름
```

<br>

### 겪었던 이슈

**상황** : [편리한 깃헙페이지 블로깅을 위한 이미지서버, 구글드라이브: 업로드 ShellScript편](https://beomi.github.io/2017/03/27/Use-GoogleDrive-as-Image-Server/) 를 내 컴퓨터에 적용하던 중, 캡처를 위해 만든 쉘스크립트 파일을 매번 긴 명령어를 통해 실행하기 번거롭기 때문에 alias를 적용하려던 중 생긴 에러였다.

나는 zsh를 사용하기 때문에 `.zshrc` 파일 최하단에 다음과 같이 작성하였다.

![](https://drive.google.com/uc?id=0B3Or0Wv2t1xwZ0RDLTdCbG9PN00)

하지만 다음과 같이 bad assignment 라는 에러 메세지와 함께 alias 지정한 capt 역시 사용이 불가능해졌다.

![https://drive.google.com/uc?id=0B3Or0Wv2t1xwWG9wbVd2MFRxVWc](https://drive.google.com/uc?id=0B3Or0Wv2t1xwWG9wbVd2MFRxVWc)

[원인을 찾아본 결과](http://stackoverflow.com/questions/19920019/zshrc-config-file-syntax-error) alias명과 명령어 사이의 **= 양 옆에 띄어쓰기가 있으면 안되는 거였다**..ㄱ-<br>그래서 띄어쓰기를 없애  `alias capt="source capture.sh"` 로 고쳐주었더니 정상적으로 작동되었다. 문법에 예민한 쉘스크립트인 만큼 무의식적으로 = 옆에 띄어쓰기를 쓰지 않도록 신경 써야겠다.