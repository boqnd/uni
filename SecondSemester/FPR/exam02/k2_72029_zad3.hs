main :: IO ()
main = do 
  -- print (isPrimeDictionary t3 vocabulary)

type Vocabulary = [String]

data BTree = Nil | Node Char BTree BTree deriving (Show)

vocabulary :: Vocabulary
vocabulary = ["the", "a", "Some", "swimming", "liStS", "lisp"]

t1 :: BTree
t1 = Node 'a' (Node 't' (Node 'l' (Node 't' Nil Nil) (Node 'h' Nil Nil)) (Node 'i' (Node 'e' Nil Nil) (Node 'l' Nil Nil))) (Node 'h' (Node 's' (Node 'i' Nil Nil) (Node 'S' Nil Nil)) (Node 'a' (Node 't' Nil Nil) (Node 'S' Nil Nil)))

t2 :: BTree
t2 = Node 'a' (Node 't' (Node 'l' (Node 't' Nil Nil) (Node 'h' Nil Nil)) (Node 'i' (Node 'e' Nil Nil) (Node 'l' Nil Nil))) (Node 'h' (Node 's' (Node 'i' Nil Nil) (Node 's' Nil Nil)) (Node 'p' (Node 'p' Nil Nil) (Node 'S' Nil Nil)))

t3 :: BTree
t3 = Node 'a' (Node 't' (Node 'l' Nil Nil) (Node 'i' Nil Nil)) (Node 'h' (Node 's' Nil Nil) (Node 'p' Nil Nil))

-- isPrimeDictionary :: BTree -> Vocabulary -> Bool
-- isPrimeDictionary tree voc = [(w, i) | (w,i) <- zip (getLeveledWords tree) [0..]]......

-- todo ..
-- ne mi stigna vremeto no vsichki pomoshtni funkcii koito mi trqbvat sa napisani. Ostana mi samo da gi sglobya.

getLeveledWords :: BTree -> [String]
getLeveledWords tree = helper tree 0
 where
  helper Nil level = []
  helper tree level
    | level <= (getLevels tree) = (getWordFromLevel tree level):(helper tree (level+1))
    | otherwise = []

getWordFromLevel :: BTree -> Int -> String
getWordFromLevel Nil l = ""
getWordFromLevel (Node x lt rt) l
  | l == 0 = [x]
  | otherwise = (getWordFromLevel lt (l-1)) ++ (getWordFromLevel rt (l-1))

getLevels :: BTree -> Int
getLevels (Node x Nil Nil) = 0
getLevels (Node x lt Nil) = 1 + (getLevels lt)
getLevels (Node x Nil rt) = 1 + (getLevels rt)
getLevels (Node x lt rt) = 1 + (max (getLevels lt) (getLevels rt))

substring :: String -> String -> Bool
substring str [] = False
substring [] sub = False
substring str sub = helper str sub sub
  where
    helper [] _ (c:cu) =  False
    helper (s:st) sub [] = False
    helper _ sub [] = True
    helper (s:st) sub (c:cu)
      | not (s == c) = helper st sub (c:cu)
      | otherwise = helper st sub cu