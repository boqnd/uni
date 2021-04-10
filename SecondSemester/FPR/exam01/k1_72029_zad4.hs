main :: IO ()
main = do 
  print (scoreHand ["A"])
  print (scoreHand ["A","J"])
  print (scoreHand ["5","3","7"])
  print (scoreHand ["5","4","3","2","A","K"])
  print (scoreHand ["2","3"])
  print (scoreHand ["4","5","6"])
  print (scoreHand ["7","7","8"])
  print (scoreHand ["K","J","Q"])
  print (scoreHand ["A","3"])
  print (scoreHand ["A","A"])
  print (scoreHand ["A", "10", "A"])
  print (scoreHand ["A","2","A","9","9"])
  --print (scoreHand ["A","2","A","9","p"])

scoreHand :: [String] -> Int
scoreHand xs = helper xs 0 False
  where
    helper :: [String] -> Int -> Bool -> Int
    helper [] score False = score
    helper [] score True = if score <= 11 then (score+10) else score
    helper (x:xs) score flag
      | x == "A"  = helper xs (score+1) True 
      | x == "2"  = helper xs (score+2) flag 
      | x == "3"  = helper xs (score+3) flag 
      | x == "4"  = helper xs (score+4) flag 
      | x == "5"  = helper xs (score+5) flag 
      | x == "6"  = helper xs (score+6) flag 
      | x == "7"  = helper xs (score+7) flag 
      | x == "8"  = helper xs (score+8) flag 
      | x == "9"  = helper xs (score+9) flag 
      | x == "10" = helper xs (score+10) flag 
      | x == "J"  = helper xs (score+10) flag 
      | x == "Q"  = helper xs (score+10) flag 
      | x == "K"  = helper xs (score+10) flag
      | otherwise = error "Wrong card!"
      

