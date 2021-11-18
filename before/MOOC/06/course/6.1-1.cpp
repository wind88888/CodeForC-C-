// //图的邻接矩阵表示法

// #define MaxVertexNum 100  //最大定点数设为100
// #define INFINITY 65535   //无穷大设为无符号整数的最大值65535
// typedef int Vertex;     //用顶点下标表示顶点，为整型
// typedef int WeightType;//边的权值设为整型
// typedef char DataType;//顶点存储的数据类型设为字符型

// //边的定义
// typedef struct ENode *PtrToENode;
// struct ENode{
//     Vertex V1,V2;      //有向边<V1,V2>
//     WeightType Weight;//权重
// };
// typedef PtrToENode Edge;

// //图节点的定义
// typedef struct GNode *PtrToGNode;
// struct GNode
// {
//     int Nv; //顶点数
//     int Ne; //边数
//     WeightType G[MaxVertexNum][MaxVertexNum];//邻接矩阵
//     DataType Data[MaxVertexNum];     //存顶点的数据
//     //注意，很多情况下，顶点无数据，此时Data[]可以不用出现
// };
// typedef PtrToGNode MGraph;//以邻接矩阵存储的图类型

// MGraph CreateGraph(int VertexNum)
// {//初始化一个有VertexNum个顶点但没有边的图
//     Vertex V,W;
//     MGraph Graph;

//     Graph=(MGraph)malloc(sizeof(struct GNode));//建立图
//     Graph->Nv = VertexNum;
//     Graph->Ne = 0;
//     //初始化邻接矩阵
//     //注意：这里默认顶点编号从0开始，到(Graph->Nv-1)
//     for (V=0; V<Graph->Nv; V++)
//         for (W=0; W<Graph->Nv; W++) 
// }