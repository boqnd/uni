main :: IO ()
main = do
  print (inorder (mirrorTree t2))

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