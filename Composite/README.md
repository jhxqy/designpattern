## ***Composite*** 组合模式

### 意图：
>将对象组合成树形结构以表示部分-整体的层次结构，使得单个对象和对象容器的使用有一致性；

### 适用性：
* 想表示对象的部分-整体层次结构
* 希望用户忽略组合对象和单个对象的不同

### 实现
* 在component类中定义**父组件引用**可以简化操作
* 最大化component接口
* 最好由composite删除其子节点