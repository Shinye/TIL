#해시테이블

[https://www.youtube.com/watch?v=tjtFkT97Xmc](https://www.youtube.com/watch?v=tjtFkT97Xmc)

used when speedy insertion, deletion, and lookup of an element is priority. 

in theory, insertion, deletion, and lookup(검색) can be accomplished in constant time.

hash table is an array coupled with(~와 결부된) a ‘hash function’

hash function has a piece of data as input, we’ll call this a key, 

and outputs an integer, commonly referred to as a hash value

The hash value maps(배치, 구조 등에 대한 정보를 발견하다,보여주다) our key to a particular index in the hash table.

You’d initially use the hash function to determine where in the hash table to store a given key.

Later, you’d use the same hash function to determine where in the hash table to search for a given key.

This function computes a hash value based on the

first letter of the key.

Linked lists can get bigger and smaller but they take up more size.

Arrays are much more straightforward to use but they’re restrictive in as much as we have to

set a size of the array at the very beginning and then we’re stuck with it.

-Hash Tables-

ARRAY(advantages : ex:random access. without having to iterate across) 

+ 

LINKED LIST(we want to have our DS be able to grow and shrink.

Hash tables combine the random access ability of an array with the dynamism of a linked list..

THIS MEANS! (assuming we define our hash table well

- Insertion can start to tend toward 세타(1) // 세타 : 평균
- Deletion can start to tend toward 세타(1)
- Lookup can start to tend toward 세타(1)

Specifically we want the data itself to tell us where it should go in the structure.

but if you start to use HT to order or sort data, you lose all of the advantages you previously have

in terms of insertion and deletion. 

So we only want to use hash tables if we don’t care about whether data is sorted.

A hash table amounts to a combination of two things with which we’re quite familiar.

- First, a hash function, which returns an nonnegative integer value called a ‘hash code’
- Second, an array capable of storing data of the type we wish to place into data structure

The Basic Idea;

we take some data, and we run that data through the hash function. And so

the data is processed and it spits out a number.

And then, with that number, we just store the data we want to store in the array at the location. 

ex) we have this hash table of strings. it’s got 10 elements in ite. so we can fit 10 strings in it.

\>> string hashtable[10];

Let’s say we want to hash John. John as the data we want to insert into this hash table somewhere.

\>> int x = hash(“John”); // x is now 4

Where do we put it? Well, typically with an array, we probably would put it in array location 0.

But! now we have this new hash function. 

And let’s say that we run John through this hash function and it’s spit out 4.

4 is where we’re going to want to put John. 

We want to put John in array location 4. because if we hash John again, 

let’s say later we want to search and see if John exists in this hash table.

-> all we need to do is run it through the same hash function. 

get the number 4 out and be able to find John immediately in our Data Structure

\>> hashtable[x] = “John”;

How to define a hash function? Really no limit to the number of possible hash functions.

A good hash function should : 

- Use only the data being hashed
- Use all of the data being hashed
- Be deterministic (Every time we pass the exact same piece of data into the hash function we always get the same hash code out. 해시함수를 100번 돌려도 John에 대한 해시코드는 무조건 4가 나오도록.)
- Uniformly distribute data  (If every time you run data through the hash function you get the hash code 0, that’s not so great. you want big range of hash code. Also things can be spread out throughout the table. 해시함수를 돌린 결과값(해시코드)가 골고루 분포되어 출력되야 한다. 예를들어 항상 0만 나오면 안되는…)
- Generate very different hash codes for very similar data(비슷한 데이터라 할지라도 해시코드는 골고루 분포될 수 있도록 해야함. cat과 cattle의 위치는 멀어야한다.)

해시테이블의 단점 : Collision

The Collision occurs when two pieces of data run through the same hash function yield the same hashcode

만약 크기 10의 해시테이블에 [3]과 [6]의 위치에 데이터가 저장되어있다고 가정하자. 

여기서 새 데이터를 넣기 위해 해시함수를 돌리는데 또다시 6이 나왔다. 6의 위치에 저장하고 싶지만 이미 6의 위치엔 기존의 데이터가 저장되어 있는 상황이 발생할 수 있다. 이런 경우를 Collision이라고 부른다.

Resolving collisions : Linear probing

- In this method, if we have a collision, we try to place the data in the next consecutive element in the array(wrapping around to the beginning if necessary) until we find a vacancy.
- That way, if we don’t find what we’re looking for in the first location, at least hopefully the element is somewhere nearby

Resolving collisions : Chaining.

- What if instead of each element of the array holding just one piece of data, it held multiple pieces of data?
- If each element of the array is a pointer to the head of a linked list, then multiple pieces of data can yield the same hash code and we’ll be able o store it all.

“What if every element of the array was a pointer to the head of a linked list?”

and grow them arbitrarily(마음대로) because linked lists allow us to grow and shrink a lot more flexibly than an array does. now we can fit an infinite amount of data into our hash table without ever running into the problem of collision. we’ve also eliminated clustering by doing this. 

But you know…lookup in linked list have a problem. we have to search it from beginning to end.There’s no random access in a linked list. 

But if instead of having one linked list where a lookup would be O of N,
