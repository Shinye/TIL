#-*- coding: utf-8 -*-

article = unicode(open("article.txt").read().decode("utf-8"))
#파이썬에서 문자열 처리하려면 무조건 unicode처리
#파이썬에서 처리할 수 있는 문자열은 unicode

import string
exclude = set(string.punctuation)
print exclude

article_line = article.strip().split("\n")
for idx, line in enumerate(article_line):
    s = ''.join([ch for ch in line if ch not in exclude])
    article_line[idx] = s

for line in article_line:
    print line

from konlpy.tag import Twitter
from konlpy.utils import pprint

tknzer = Twitter()
row = tknzer.nouns(article_line[0])
pprint(row)

voca = []
for line in article_line:
    row = tknzer.nouns(line)
    voca.extend(row)

voca = list(set(voca))
pprint(voca)

print len(voca)
voca_idx = { w : idx for idx, w in enumerate(voca)}
pprint(voca_idx)

trg_matrix = []
for line in article_line:
    row = tknzer.nouns(line)
    bag_of_words = [0 for x in range(len(voca))]
    for word in row:
        if word in voca:
            bag_of_words[voca_idx[word]] += 1 
    trg_matrix.append(bag_of_words)

print trg_matrix


import numpy as np
feat_mat = np.array(trg_matrix)
U,s,Vh = np.linalg.svd(feat_mat, full_matrices = False)
Wonhae = np.matmul(U,np.diag(s))
mutual_point = np.matmul(Wonhae, np.transpose(Wonhae)).sum(axis=1)


print mutual_point
rank = np.argsort(mutual_point)[::-1]
print rank
for r in rank:
    print "(point : )", mutual_point[r], ")", article_line[r]
