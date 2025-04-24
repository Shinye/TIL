# Time / Space Complexity

### O(1)는 정말로 공간이 1개만 필요하다는 의미는 아니다

(21_merge_two_sorted_list.kt 를 풀며..)

O(1)이 **정말 "변수가 딱 하나만 있어야 한다"** 는 뜻은 아니에요.<br/>
좀 더 정확히 말하자면:

💡 O(1)의 의미<br />
**입력 크기(n)**에 비례하지 않는 상수 공간만 사용하는 경우를 O(1) 공간복잡도라고 해요.

- 변수 1개든, 2개든, 10개든 고정된 개수라면 → O(1)
- 하지만 n개의 데이터를 저장하는 배열이나 리스트를 만든다면 → O(n)

✅ O(1) 공간 복잡도 예시

```kotlin
var max = Int.MIN_VALUE
for (i in 0 until nums.size) {
max = maxOf(max, nums[i])
}
```

변수 하나(max)만 쓰고, 리스트 크기와 무관 → O(1)

❌ O(n) 공간 복잡도 예시

```kotlin
val output = mutableListOf<Int>()
for (i in nums.indices) {
output.add(nums[i] \* 2)
}
```

nums의 크기만큼 새로운 리스트 생성 → O(n)

🤔 그럼 prehead, prev 같은 포인터 2개도?
**2개든 10개든, 입력 사이즈에 따라 늘지 않으면 O(1)**입니다.

리스트 노드 수가 100만 개가 되어도, 포인터 변수는 여전히 딱 2개 → 상수 공간

📌 결론

O(1)은 공간 1개만 써야 한다 ❌ <br/>
O(1)은 입력 크기와 무관하게 고정된 공간만 사용한다 ✅

그래서 prehead, prev 두 포인터만 쓰는 것도 O(1)이 맞아요!
