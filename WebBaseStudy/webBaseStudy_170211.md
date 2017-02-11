인터넷을 연결하기 위하여 필요한 것들!

나 ——ㅇ—>인터넷

이 사이에 뭐가 있을깡?

**1.  IP주소 (Internet Protocol Address)**

A unique identifier of your computer network.

Just like evert home or office has a unique address to which one could send a mail.

Similarly, every computer if it wants to receive data or send data, needs to have a unique address. 

IP주소를 처음 만들고자 할 땐, 모든 컴퓨터의 연결이 가능하게 하기 위해 16진수로 주소를 만들고자 시도하였으나 너무 어렵고 직관성이 떨어지니 지금의 IP주소 구조를 갖게 되었다 함.

모양 : w.x.y.z // can hold 256 distinct values.[0,255]

private address @IPAdrdress ?? [http://egloos.zum.com/xxwony/v/73126](http://egloos.zum.com/xxwony/v/73126)

**IPv6**

s:t:u:v:w:x:y:z 

인구가 늘어남에 따라 기존의 IP주소(8bit. IPv4)형식에서 벗어나 IPv6라는 새로운 형식의 아이피 주소 형태를 만들었다. 기존의 8bit가 0부터 255까지였다면 16bit는 0부터 65535까지. 가독성이 너무 떨어지니까 주로 16진수를 쓴다. [0,65535] -> [0,ffff]

아직 신생이라서 간혹 이런 주소도 보인다

2344:7843:324:0:0:0:0:423 이런 연속된 일련의 0들은 불필요하니

2344:7843:324::423 이렇게 생략해서 작성하기도 함.

**DHCP (Dynamic Host Configuration Protocol)**

IP주소를 디바이스에 할당해주는 역할.

우리가 처음 IP주소를 발급받을 때 가지고자 했던 주소 넘버를 이미 누군가 선점하고 있는 상태라면? Somewhere between your computer and the Internet at large exists a DHCP server, whose role is to assign IP addresses to devices.

DHCP server has a list of addresses that it can validly assign. And it gives you one.

It’s just a program running somewhere between you and the internet that has a bank of IP address that it can give out. And when you connect to the network, it gives you one.

**DNS (Domain Name System) : dns서버??**

**Not a giant block!**

…But you’ve never actually tried to visit a website by typing its IP addresses into your browser.

Translates IP addresses to human comprehensible words or phrases that are much more memorable than remembering a set of four numbers.

In the way, large DNS servers are like libraries that stock many different set of local yellow page books. In order to have the most up-to-date phone numbers for businesses, libraries must update the books they have on hand.

DNS record sets are thus fairly decentralized It’s decentralized across many many servers. 

**Access Points.**

actually connecting to the internet.

One of the ways we’ve dealt with the IPv4 addressing problem is, to start assigning multiple people to the same IP address.

The IP address is assigned to a router, whose job it is to act as a traffic cop that allows data requests from all of the devices on your local network(ur home or company) to be processed through a single IP address. 

Modern home networks consist of access points that combine a router, a modem, a switch, and other technologies together into a single device.

Allowing everybody who’s connected to that router to use the same IP address to get out. So everybody at your home 

=======================

IP (Internet Protocol)

“The Internet” is an interconnected network comprised of smaller networks woven together and agreeing to communicate with one another.

How do these networks know how to communicate with one another? this is the responsibility of the IP. This dictates how information is transmitted from point A to point B.

모든 시스템들을 연결하기가 현실적으로 불가능하기 때문에 

TCP

HTTP