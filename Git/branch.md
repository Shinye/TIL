# 브랜치 따기

## branch 관련 명령어들

우선 브랜치와 관련 된 명령어들은 다음과 같다.

```shell
$ git branch # 현재 내 저장소에 어떤 브랜치들이 있는지, 어떤 브랜치 안에 있는지 보여준다.
$ git checkout 브랜치명 # 작성한 브랜치명의 브랜치로 이동한다.
$ git checkout -b 브랜치명 # 브랜치를 새로 생성하고, 생성한 브랜치로 이동한다.
```



## 예시

![https://78.media.tumblr.com/6f423fffc3a334dc358d77bf263ae874/tumblr_oyy3zgQL931v80c66o8_1280.png](https://78.media.tumblr.com/6f423fffc3a334dc358d77bf263ae874/tumblr_oyy3zgQL931v80c66o8_1280.png)

1. 우선 `master` 에서 두 개의 파일을 만들어 github에 push 한다.



![https://78.media.tumblr.com/62edd57d8ccf7a92a7dbc98a0941f004/tumblr_oyy3zgQL931v80c66o7_1280.png](https://78.media.tumblr.com/62edd57d8ccf7a92a7dbc98a0941f004/tumblr_oyy3zgQL931v80c66o7_1280.png)

2. `git checkout -b testBranch` 명령어를 통해 브랜치를 생성 및 이동하고, 파일을 수정한다.<br>`git status` 명령을 통해 testBranch 브랜치에서 파일들이 수정되었음을 확인할 수 있다.

![https://78.media.tumblr.com/44ee98e01a7a2cbae91f9defbd66fbe5/tumblr_oyy3zgQL931v80c66o6_1280.png](https://78.media.tumblr.com/44ee98e01a7a2cbae91f9defbd66fbe5/tumblr_oyy3zgQL931v80c66o6_1280.png)

3. testBranch에서 commit을 한 후, push는 `git push origin testBranch` 로 해준다. (origin 뒤에 해당 브랜치 명을 작성해준다.)

![https://78.media.tumblr.com/dfea3fbb3f8880cfd393e9660b5b1d27/tumblr_oyy3zgQL931v80c66o3_1280.png](https://78.media.tumblr.com/dfea3fbb3f8880cfd393e9660b5b1d27/tumblr_oyy3zgQL931v80c66o3_1280.png)

4. push를 한 후 해당 레포에 들어가보면, 브랜치가 생성되었다는 알림이 보인다. 오른쪽의 Compare & Pull Request를 누른다.

![https://78.media.tumblr.com/ae1f851f08668f16c17f2b00c4ea2dc9/tumblr_oyy3zgQL931v80c66o5_1280.png](https://78.media.tumblr.com/ae1f851f08668f16c17f2b00c4ea2dc9/tumblr_oyy3zgQL931v80c66o5_1280.png)

5. 원하는 메세지를 작성해 create pull request 버튼을 누른다.



![https://78.media.tumblr.com/6cd8464ce711380df4f41811e04f4a5f/tumblr_oyy3zgQL931v80c66o9_1280.png](https://78.media.tumblr.com/6cd8464ce711380df4f41811e04f4a5f/tumblr_oyy3zgQL931v80c66o9_1280.png)

6. 버튼을 누른 후엔 다음과 같은 화면으로 이동하게 되고, (이 예시에는 participant가 나뿐이지만) 코드리뷰 등 참여자들 사이의 의논 후에 merge 해도 되는 상태가 된다면 하단의 초록 버튼을 누른다. (우리 회사의 경우 squash and merge 버튼을 누르게 한다.) <br>이 PR 과정에서 merge가 되기 위해 지속적으로 코드를 수정하기 위해선 그냥 계속 해당 브랜치에서 커밋을 하고 `push origin 해당브랜치명` 을 하면 된다. 

   ### squash란?

   `merge --squash` <br>해당 브랜치의 모든 커밋을 하나의 커밋으로 병합하여 `master` 브랜치로 가져오는 것이다. 지속해서 수정 커밋을 거친 후 쌓인 수 많은 커밋들이 마스터 브랜치에까지 닿는다면 커밋 트래킹이 어려울 수 있어 회사에서는squash를 권장하는 것이 아닌가 싶다.



7. 작업을 완료한 후의 브랜치는 지워주고,  (저 화면 다음 화면에 delete branch 버튼이 나올텐데 그려면 지워주면 된다.) 내 로컬에서도 완료된 브랜치는 지워준다. 그 후 작업 내역을 원격저장소에서 pull 해와서 `up-to-date` 해준다.

<br><br>

###참고 URL

[merge --squash](https://backlog.com/git-tutorial/kr/stepup/stepup7_7.html)<br>[(책)만들면서 배우는 Git+GitHub 입문](http://www.yes24.com/24/Goods/19684104?pid=123482&cosemkid=nc14913581731573759&n_media=27758&n_query=%EB%A7%8C%EB%93%A4%EB%A9%B4%EC%84%9C%EB%B0%B0%EC%9A%B0%EB%8A%94GITGITHUB%EC%9E%85%EB%AC%B8&n_rank=1&n_ad_group=grp-a001-01-000000000434715&n_ad=nad-a001-01-000000021380870&n_keyword_id=nkw-a001-01-000000065682981&n_keyword=%EB%A7%8C%EB%93%A4%EB%A9%B4%EC%84%9C%EB%B0%B0%EC%9A%B0%EB%8A%94GITGITHUB%EC%9E%85%EB%AC%B8&n_campaign_type=1)