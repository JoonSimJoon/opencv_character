전체 맵 900 * 900



캐릭터 픽셀 64*64



시작점 130*130 

끝점 770*770 



vec3b는 BGR의 순서로 색깔이 있다



------

```
git lfs track "*.ipch"
git add .
git commit -m"blabla"

java -jar bfg.jar --strip-blobs-bigger-than 100M
git repack && git gc
java -jar bfg.jar --strip-blobs-bigger-than 100M
git commit -m"vlavla"


```

