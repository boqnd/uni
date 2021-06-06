main :: IO ()
main = do
  print (singleCousin astt1)


data BTree = Empty | Node Int BTree BTree deriving Show

t1 :: BTree
t1 = Node 5 (Node 2 Empty (Node 3 Empty Empty) ) (Node 6 Empty Empty)

t2 :: BTree
t2 = Node 5 (Node 3 Empty Empty)(Node 4 (Node 5 Empty Empty)(Node 7 Empty Empty))

size :: BTree -> Int
size Empty = 0
size (Node v lt rt) = 1 + size lt + size rt

sumTree :: BTree -> Int
sumTree Empty = 0
sumTree (Node v lt rt) = v + (sumTree lt) + (sumTree rt)

sumLeaves :: BTree -> Int
sumLeaves Empty = 0
sumLeaves (Node v Empty Empty) = v
sumLeaves (Node v lt rt) = (sumLeaves lt) + (sumLeaves rt)

inorder :: BTree -> [Int]
inorder Empty = []
inorder (Node v lt rt) = (inorder lt) ++ [v] ++ (inorder rt)


getLevel :: Int -> BTree -> [Int]
getLevel _ Empty = []
getLevel 0 (Node v _ _) = [v]
getLevel l (Node v lt rt) = (getLevel (l-1) lt) ++ (getLevel (l-1) rt)

average :: BTree -> Double
average Empty = 0.0
average t = (fromIntegral (sumTree t)) / (fromIntegral (size t))

mirrorTree :: BTree -> BTree
mirrorTree Empty = Empty
mirrorTree (Node v lt rt) = (Node v (mirrorTree rt) (mirrorTree lt))

type AssocTree = [(Int, [Int])]

ast1 = [(4, [2, 5]), (2, [1, 3])]
ast2 = [(1,[2,3,4]),(2,[5,6]),(3,[7]),(4,[8,9]),(5,[]),(6,[10]),(7,[]),(8,[]),(9,[]),(10,[])]

twoChildrenNodes :: AssocTree -> Int
twoChildrenNodes ast = length $ filter (\ a -> (length $ snd a) == 2) ast

twoChildrenNodes' :: AssocTree -> Int
twoChildrenNodes' ast = length [v | (v, ns) <- ast, length ns == 2]

allHaveTwoChildren :: AssocTree -> Bool
allHaveTwoChildren ast = and [null ns || length ns == 2 | (v, ns) <- ast]

findUncles :: AssocTree -> Int -> [Int]
findUncles asd n
  | null us = []
  | null (head us) = []
  | otherwise = head (head us)
  where
    us = [[ ns1 | (v1, ns1) <- asd, v `elem` ns1 ]  | (v, ns) <- asd, n `elem` ns]
    --pochti
    --ima bug

astt1 :: AssocTree
astt1 = [(1,[2,3]),(2,[4,5]),(3,[6,7]),(4,[8,9]),(5,[10]),(6,[11]),(7,[12]),(8,[]),(9,[]),(10,[]),(11,[]),(12,[])]

-- singleCousin :: AssocTree -> [Int]
singleCousin ast = singleChildrenWithNoKinds
  where
    singleChildrenWithNoKinds = [head (head ns) | ns <- [[ ns1 | (v1, ns1) <- ast, v `elem` ns1, (length ns1 == 1)] | (v, ns) <- ast, (length ns == 0)], not (null ns)]
