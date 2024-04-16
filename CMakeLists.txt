cmake_minimum_required(VERSION 3.27.8)
project(08Wangdao)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp)

add_executable(
        testStaticSeqTable chapter02-Linear_List/01Sequence_table/test/testStaticSeqTable.cpp
        chapter02-Linear_List/01Sequence_table/head/static_SeqTable.h
        chapter02-Linear_List/01Sequence_table/source/static_SeqTable.cpp
)

add_executable(
        testDynamicSeqTable chapter02-Linear_List/01Sequence_table/test/testDynamicSeqTable.cpp
        chapter02-Linear_List/01Sequence_table/head/dynamic_SeqTable.h
        chapter02-Linear_List/01Sequence_table/source/dynamic_SeqTable.cpp
)

add_executable(
        oddProduct chapter02-Linear_List/01Sequence_table/LeetCode/oddProduct.cpp
        chapter02-Linear_List/01Sequence_table/head/dynamic_SeqTable.h
        chapter02-Linear_List/01Sequence_table/source/dynamic_SeqTable.cpp
)

add_executable(
        valCount chapter02-Linear_List/01Sequence_table/LeetCode/valCount.cpp
        chapter02-Linear_List/01Sequence_table/head/static_SeqTable.h
        chapter02-Linear_List/01Sequence_table/source/static_SeqTable.cpp
)

add_executable(
        singerMark chapter02-Linear_List/01Sequence_table/LeetCode/singerMark.cpp
        chapter02-Linear_List/01Sequence_table/head/dynamic_SeqTable.h
        chapter02-Linear_List/01Sequence_table/source/dynamic_SeqTable.cpp
)

add_executable(
        guessNum chapter02-Linear_List/01Sequence_table/LeetCode/guessNum.cpp
)

add_executable(
        takeCoin chapter02-Linear_List/01Sequence_table/LeetCode/takeCoin.cpp
)

add_executable(
        minIndex chapter02-Linear_List/01Sequence_table/LeetCode/minIndex.cpp
)

add_executable(
        maxNumofContinOne chapter02-Linear_List/01Sequence_table/LeetCode/maxNumofContinOne.cpp
)

add_executable(
        absoluteK chapter02-Linear_List/01Sequence_table/LeetCode/absoluteK.cpp
        chapter02-Linear_List/02Linked_list/CircularLink/Double/test/testCirDoubleLinkWithHead.cpp
        chapter05-tree/tree-Hero/source/binaryTree_Hero.cpp
        chapter05-tree/tree-Hero/head/binaryTree_Hero.h
)

add_executable(
        maxProduct chapter02-Linear_List/01Sequence_table/LeetCode/maxProduct.cpp
)

add_executable(
        sumK chapter02-Linear_List/01Sequence_table/LeetCode/sumK.cpp
)

add_executable(
        triadCount chapter02-Linear_List/01Sequence_table/LeetCode/triadCount.cpp
)

add_executable(
        removeEle chapter02-Linear_List/01Sequence_table/LeetCode/removeEle.cpp
)

add_executable(
        buildArray chapter02-Linear_List/01Sequence_table/LeetCode/buildArray.cpp
)

add_executable(
        arrayConcat chapter02-Linear_List/01Sequence_table/LeetCode/arrayConcat.cpp
)

add_executable(
        candyKid chapter02-Linear_List/01Sequence_table/LeetCode/candyKid.cpp
)

add_executable(
        arrayMiddle chapter02-Linear_List/01Sequence_table/LeetCode/arrayMiddle.cpp
)

add_executable(
        singleEle chapter02-Linear_List/01Sequence_table/LeetCode/singleEle.cpp
)

add_executable(
        yanghuiTriangle chapter02-Linear_List/01Sequence_table/LeetCode/yanghuiTriangle.cpp
)

add_executable(
        testSingleLinkWithHead chapter02-Linear_List/02Linked_list/SingleLink/test/testSingleLinkWithHead.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        testSingleLinkWithoutHead chapter02-Linear_List/02Linked_list/SingleLink/test/testSingleLinkWithoutHead.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithoutHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithoutHead.cpp
)

add_executable(
        sumArray chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/sumArray.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        orderList chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/orderList.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        superStair chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/superStair.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        binaryInvertPos chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/binaryInvertPos.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        countBack_K chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/countBack_K.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        trainPlan chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/trainPlan.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        middleNode chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/middleNode.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        delMiddleNode chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/delMiddleNode.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        removeElem chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/removeElem.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        delNode chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/delNode.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        delRepeatEle chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/delRepeatEle.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        delCountBack_N chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/delCountBack_N.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        remRepeatNode chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/remRepeatNode.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        arrangeBook chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/arrangeBook.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        reverseLink chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/reverseLink.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        testDoubleLinkWithHead.cpp chapter02-Linear_List/02Linked_list/DoubleLink/test/testDoubleLinkWithHead.cpp
        chapter02-Linear_List/02Linked_list/DoubleLink/head/doubleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/DoubleLink/source/doubleLinkWithHead.cpp
)

add_executable(
        trainPlan3 chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/trainPlain3.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        reverseLink2 chapter02-Linear_List/02Linked_list/SingleLink/LeetCode/reverseLink2.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(
        testStaticStack chapter03-stack-queue/Stack/test/testStaticStack.cpp
        chapter03-stack-queue/Stack/head/staticStack.h
        chapter03-stack-queue/Stack/source/staticStack.cpp
)

add_executable(
        teststaticSharedStack chapter03-stack-queue/Stack/test/teststaticSharedStack.cpp
        chapter03-stack-queue/Stack/head/staticSharedStack.h
        chapter03-stack-queue/Stack/source/staticSharedStack.cpp
)

add_executable(
        testLinkStack chapter03-stack-queue/Stack/test/testLinkStack.cpp
        chapter03-stack-queue/Stack/head/LinkStack.h
        chapter03-stack-queue/Stack/source/LinkStack.cpp
)

add_executable(
        teststaticStack_Hero chapter03-stack-queue/Stack/test/teststaticStack_Hero.cpp
        chapter03-stack-queue/Stack/head/staticStack_Hero.h
        chapter03-stack-queue/Stack/source/staticStack_Hero.cpp
)

add_executable(
        testLinkStack_Hero chapter03-stack-queue/Stack/test/testLinkStack_Hero.cpp
        chapter03-stack-queue/Stack/head/LinkStack_Hero.h
        chapter03-stack-queue/Stack/source/LinkStack_Hero.cpp
)

add_executable(testCppStack chapter03-stack-queue/Stack/test/testCppStack.cpp
        chapter04-string/LeetCode/countNumofString.cpp)

add_executable(
        decToBinary chapter03-stack-queue/Stack/LeetCode/decToBinary.cpp
        chapter03-stack-queue/Stack/head/LinkStack.h
        chapter03-stack-queue/Stack/source/LinkStack.cpp
)

add_executable(
        dectoAny chapter03-stack-queue/Stack/LeetCode/decToAny.cpp
        chapter03-stack-queue/Stack/head/LinkStack.h
        chapter03-stack-queue/Stack/source/LinkStack.cpp
)

add_executable(
        arrangeBook_Stack chapter03-stack-queue/Stack/LeetCode/arrangeBook_Stack.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
        chapter03-stack-queue/Stack/LeetCode/stackRealizeQueue.cpp
)

add_executable(
        palindromeLink chapter03-stack-queue/Stack/LeetCode/palindromeLink.cpp
        chapter02-Linear_List/02Linked_list/SingleLink/head/singleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/SingleLink/source/singleLinkWithHead.cpp
)

add_executable(validBracket chapter03-stack-queue/Stack/LeetCode/validBracket.cpp)

add_executable(
        testStaticQueue chapter03-stack-queue/Queue/test/testStaticQueue.cpp
        chapter03-stack-queue/Queue/head/staticQueue.h
        chapter03-stack-queue/Queue/source/staticQueue.cpp
)


add_executable(
        testdoublePointLinkQueueWithoutHead chapter03-stack-queue/Queue/test/testdoublePointLinkQueueWithoutHead.cpp
        chapter03-stack-queue/Queue/head/doublePointLinkQueueWithoutHead.h
        chapter03-stack-queue/Queue/source/doublePointLinkQueueWithoutHead.cpp
)

add_executable(
        bracketMatch chapter03-stack-queue/Stack/LeetCode/bracketMatch.cpp
        chapter03-stack-queue/Stack/head/LinkStack.h
        chapter03-stack-queue/Stack/source/LinkStack.cpp
)

add_executable(
        infixToSuffix chapter03-stack-queue/Stack/LeetCode/infixToSuffix.cpp
)

add_executable(
        infixToPrefix chapter03-stack-queue/Stack/LeetCode/infixToPrefix.cpp
)

add_executable(
        calcFixExpre chapter03-stack-queue/Stack/LeetCode/calcFixExpre.cpp
)

add_executable(
        stackFactorial chapter03-stack-queue/Stack/LeetCode/stackFactorial.cpp
)

add_executable(
        Fibonacci_array chapter03-stack-queue/Stack/LeetCode/Fibonacci_array.cpp
)

add_executable(
        symmetricMatrix chapter03-stack-queue/Stack/LeetCode/symmetricMatrix.cpp
)

add_executable(
        sparseMatrix chapter03-stack-queue/Stack/LeetCode/sparseMatrix.cpp
)

add_executable(
        UpperTriangularMatrix chapter03-stack-queue/Stack/LeetCode/UpperTriangularMatrix.cpp
)

add_executable(
        LowerTriangularMatrix chapter03-stack-queue/Stack/LeetCode/LowerTriangularMatrix.cpp
)

add_executable(
        soldierQueue chapter03-stack-queue/Queue/LeetCode/soldierQueue.cpp
)

add_executable(
        twoDimenQueue chapter03-stack-queue/Queue/LeetCode/twoDimenQueue.cpp
)

add_executable(
        recentRequest chapter03-stack-queue/Queue/LeetCode/recentRequest.cpp
)

add_executable(
        stackRealizeQueue chapter03-stack-queue/Stack/LeetCode/stackRealizeQueue.cpp
)

add_executable(
        queueRealizeStack chapter03-stack-queue/Queue/LeetCode/queueRealizeStack.cpp
)

add_executable(
        testLinkString chapter04-string/test/testLinkString.cpp
        chapter04-string/head/staticString.h
        chapter04-string/source/staticString.cpp
        chapter04-string/test/testHeroString.cpp
)

add_executable(
        KMP chapter04-string/LeetCode/KMP.cpp
)

add_executable(
        insertSort chapter08-sort/insertSort.cpp
)

add_executable(
        hillSort chapter08-sort/hillSort.cpp
)


add_executable(
        KMP_WangDao chapter04-string/LeetCode/KMP_WangDao.cpp
)

add_executable(
        testHeroString chapter04-string/test/testHeroString.cpp
)

add_executable(
        countChar chapter04-string/LeetCode/countChar.cpp
)

add_executable(
        upperFirstLetter chapter04-string/LeetCode/upperFirstLetter.cpp
)

add_executable(
        findMax chapter04-string/LeetCode/findMax.cpp
)

add_executable(
        judgeColor chapter04-string/LeetCode/judgeColor.cpp
)

add_executable(
        pathEncrypte chapter04-string/LeetCode/pathEncrypte.cpp
)

add_executable(
        subString chapter04-string/LeetCode/subString.cpp
)

add_executable(
        manipulateVal chapter04-string/LeetCode/manipulateVal.cpp
)

add_executable(
        ipInvalid chapter04-string/LeetCode/ipInvalid.cpp
)

add_executable(
        countStars chapter04-string/LeetCode/countStars.cpp
)

add_executable(
        splitBalanceString chapter04-string/LeetCode/splitBalanceString.cpp
)

add_executable(
        dynamicPassword chapter04-string/LeetCode/dynamicPassword.cpp
)

add_executable(
        GoalResolver chapter04-string/LeetCode/GoalResolver.cpp
)

add_executable(
        countNumofString chapter04-string/LeetCode/countNumofString.cpp
)

add_executable(
        testTree chapter05-tree/tree-Hero/test/testTree.cpp
        chapter05-tree/tree-Hero/head/Tree.h
        chapter05-tree/tree-Hero/source/Tree.cpp
        chapter05-tree/tree-Hero/test/testBinaryTree_Hero.cpp
)

add_executable(
        testStaticBinaryTree chapter05-tree/binaryTree/test/testStaticBinaryTree.cpp
        chapter05-tree/binaryTree/head/staticBinaryTree.h
        chapter05-tree/binaryTree/source/staticBinaryTree.cpp
)

add_executable(
        testHuffmanTree chapter05-tree/binaryTree/test/testHuffmanTree.cpp
        chapter05-tree/binaryTree/head/huffmanTree.h
        chapter05-tree/binaryTree/source/huffmanTree.cpp
)

add_executable(
        testDisjointSet chapter05-tree/binaryTree/test/testDisjointSet.cpp
        chapter05-tree/binaryTree/head/DisjointSet.h
        chapter05-tree/binaryTree/source/DisjointSet.cpp
)

add_executable(
        testCirDoubleLinkWithHead chapter02-Linear_List/02Linked_list/CircularLink/Double/test/testCirDoubleLinkWithHead.cpp
        chapter02-Linear_List/02Linked_list/CircularLink/Double/head/cirDoubleLinkWithHead.h
        chapter02-Linear_List/02Linked_list/CircularLink/Double/source/cirDoubleLinkWithHead.cpp
)

add_executable(
        testlinkBinaryTree chapter05-tree/binaryTree/test/testlinkBinaryTree.cpp
        chapter05-tree/binaryTree/head/linkBinaryTree.h
        chapter05-tree/binaryTree/source/linkBinaryTree.cpp
)

add_executable(
        judgeRoot chapter05-tree/LeetCode/judgeRoot.cpp
        chapter05-tree/binaryTree/head/staticBinaryTree.h
        chapter05-tree/binaryTree/source/staticBinaryTree.cpp
        chapter05-tree/LeetCode/calDepthofBinaryTree.cpp
)
add_executable(
        maxDepth chapter05-tree/LeetCode/maxDepth.cpp
        chapter05-tree/binaryTree/head/staticBinaryTree.h
        chapter05-tree/binaryTree/source/staticBinaryTree.cpp
)

add_executable(
        calDepthofBinaryTree chapter05-tree/LeetCode/calDepthofBinaryTree.cpp
        chapter05-tree/binaryTree/head/staticBinaryTree.h
        chapter05-tree/binaryTree/source/staticBinaryTree.cpp
)

add_executable(
        calcBoolbinaryTree chapter05-tree/LeetCode/calcBoolbinaryTree.cpp
        chapter05-tree/binaryTree/head/staticBinaryTree.h
        chapter05-tree/binaryTree/source/staticBinaryTree.cpp
)

add_executable(
        testBinaryTree_Hero chapter05-tree/tree-Hero/test/testBinaryTree_Hero.cpp
        chapter05-tree/tree-Hero/head/binaryTree_Hero.h
        chapter05-tree/tree-Hero/source/binaryTree_Hero.cpp
)

add_executable(
        singleValTree chapter05-tree/LeetCode/singleValTree.cpp
        chapter05-tree/tree-Hero/head/binaryTree_Hero.h
        chapter05-tree/tree-Hero/source/binaryTree_Hero.cpp
)

add_executable(
        countNodes chapter05-tree/LeetCode/countNodes.cpp
        chapter05-tree/tree-Hero/head/binaryTree_Hero.h
        chapter05-tree/tree-Hero/source/binaryTree_Hero.cpp
)

add_executable(
        preTravel chapter05-tree/LeetCode/preTravel.cpp
        chapter05-tree/tree-Hero/head/binaryTree_Hero.h
        chapter05-tree/tree-Hero/source/binaryTree_Hero.cpp
)

add_executable(
        inTravel chapter05-tree/LeetCode/inTravel.cpp
        chapter05-tree/tree-Hero/head/binaryTree_Hero.h
        chapter05-tree/tree-Hero/source/binaryTree_Hero.cpp
)

add_executable(
        postTravel chapter05-tree/LeetCode/postTravel.cpp
        chapter05-tree/tree-Hero/head/binaryTree_Hero.h
        chapter05-tree/tree-Hero/source/binaryTree_Hero.cpp
)

add_executable(
        filpRootNode chapter05-tree/LeetCode/filpRootNode.cpp
        chapter05-tree/tree-Hero/head/binaryTree_Hero.h
        chapter05-tree/tree-Hero/source/binaryTree_Hero.cpp
)

add_executable(
        countBinary chapter05-tree/LeetCode/countBinary.cpp
        chapter05-tree/tree-Hero/head/binaryTree_Hero.h
        chapter05-tree/tree-Hero/source/binaryTree_Hero.cpp
)

add_executable(
        testBinarySearchTree chapter05-tree/tree-Hero/test/testBinarySearchTree.cpp
        chapter05-tree/tree-Hero/head/binarySearchTree.h
        chapter05-tree/tree-Hero/source/binarySearchTree.cpp
)

