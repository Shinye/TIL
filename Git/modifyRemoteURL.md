# Git 원격 저장소 URL 변경하기

기존의 원격 저장소의 URL을 변경하고 싶을 땐 `git remote set-url [새 저장소 주소]` 를 사용하면 된다.

```shell
$ git remote -v
# View existing remotes
origin  https://github.com/user/repo.git (fetch)
origin  https://github.com/user/repo.git (push)

$ git remote set-url origin https://github.com/user/repo2.git

# Change the 'origin' remote's URL
$ git remote -v

# Verify new remote URL
origin  https://github.com/user/repo2.git (fetch)
origin  https://github.com/user/repo2.git (push)

```



### 참고 URL

[[번역]GitHub / Managing Remotes / 원격 저장소 URL 변경하기](http://minsone.github.io/git/github-managing-remotes-changing-a-remotes-url) 