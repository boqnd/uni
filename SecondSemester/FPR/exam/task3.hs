main :: IO ()
main = do
  print (cook [ApplePie, ApplePie, Burger, Chicken, Chicken, ApplePie])

data Dish = ApplePie | Burger | Chicken deriving (Show, Eq)

data Wether = Sunny | Rainy deriving (Show, Eq)

cook :: [Dish] -> [Wether]
cook (x:y:ds) = if (x == y) then Sunny:(cook (x:ds)) else Rainy:(cook (y:ds))
cook (x:ds) = []