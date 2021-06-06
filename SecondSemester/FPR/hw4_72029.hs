main :: IO ()
main = do
  print ("Task1")
  print (getFeaturedStars "MGM" 1995 db)
  print (getFeaturedStars "USA Entertainm." 2001 db)
  print (getPresident "Paramount" db)
  print (getPresident "Fox" db)
  print (getPresident "USA Entertainm." db)
  print (getHigherProductions "Calvin Coolidge" db)
  print (getHigherProductions "Stephen Spielberg" db)
  print (getHigherProductions "George Lucas" db)
  print ("Task2")
  print (toBinaryIndexed t1)
  print (toBinaryIndexed t2)



type Name = String
type Title = String
type Address = String
type Year = Int
type Gender = Char
type Length = Int
type ProducerID = Int
type Networth = Integer

data Movie = Movie Title Year Length Name ProducerID deriving Show
data MovieStar = MovieStar Name Gender deriving Show
data StarsIn = StarsIn Name Title deriving Show
data Studio = Studio Name Int deriving Show
data MovieExec = MovieExec Name ProducerID Networth deriving Show

type MovieDB = ([Movie], [MovieStar], [StarsIn], [Studio], [MovieExec])

getFeaturedStars :: Name -> Int -> MovieDB -> [Name]
getFeaturedStars studio_name year (m, ms, si, s, me) = [y | (y:ys):xs <- [[[name | (Movie title_ year_ l st_name pid) <- m, title == title_, year == year_, studio_name == st_name] | (StarsIn name_ title) <- si, name == name_] | (MovieStar name g) <- ms]]

getPresident :: Name -> MovieDB -> Name
getPresident studio_name (m, ms, si, s, me) = head [x | x:xs <- [[name_ | (MovieExec name_ id_ nw) <- me , id == id_] | (Studio name id) <- s, studio_name == name]]

getHigherProductions :: Name -> MovieDB -> [Name]
getHigherProductions prod_name (m, ms, si, s, me) = concat (head [[[title | (Movie title y l s pid) <- m, pid == id_] | (MovieExec name_ id_ nw_) <- me, nw_ > nw] | (MovieExec name id nw) <- me, name == prod_name])

studios :: [Studio]
studios = [Studio "Disney" 199,
          Studio "USA Entertainm." 222,
          Studio "Fox" 333,
          Studio "Paramount" 123,
          Studio "MGM" 555]

movieExecs :: [MovieExec]
movieExecs = [MovieExec "George Lucas" 555 200000000,
              MovieExec "Ted Turner" 333 125000000,
              MovieExec "Stephen Spielberg" 222 100000000,
              MovieExec "Merv Griffin" 199 112000000,
              MovieExec "Calvin Coolidge" 123 20000000]

movies :: [Movie]
movies = [Movie "Pretty Woman" 1990 119 "Disney" 199,
          Movie "The Man Who Wasn't There" 2001 116 "USA Entertainm." 555, Movie "Logan's run" 1976 120 "Fox" 333,
          Movie "Star Wars" 1977 124 "Fox" 555,
          Movie "Empire Strikes Back" 1980 111 "Fox" 555,
          Movie "Star Trek" 1979 132 "Paramount" 222,
          Movie "Star Trek: Nemesis" 2002 116 "Paramount" 123,
          Movie "Terms of Endearment" 1983 132 "MGM" 123,
          Movie "The Usual Suspects" 1995 106 "MGM" 199,
          Movie "Gone With the Wind" 1938 238 "MGM" 123,
          Movie "The Fellowship of the Ring" 2001 178 "USA Entertainm." 222]

stars :: [MovieStar]
stars = [MovieStar "Jane Fonda" 'F',
         MovieStar "Alec Baldwin" 'M',
         MovieStar "Kim Basinger" 'F',
         MovieStar "Harrison Ford" 'M',
         MovieStar "Debra Winger" 'F',
         MovieStar "Jack Nicholson" 'M',
         MovieStar "Sandra Bullock" 'F',
         MovieStar "Orlando Bloom" 'M',
         MovieStar "Cate Blanchett" 'F',
         MovieStar "Liv Tyler" 'F',
         MovieStar "Billy Bob Thornton" 'M',
         MovieStar "Scarlett Johansson" 'F']

starsIn :: [StarsIn]
starsIn = [StarsIn "Kim Basinger" "Star Wars",
           StarsIn "Alec Baldwin" "Star Wars",
           StarsIn "Harrison Ford" "Star Wars",
           StarsIn "Harrison Ford" "Empire Strikes Back",
           StarsIn "Jack Nicholson" "The Usual Suspects",
           StarsIn "Jane Fonda" "Terms of Endearment",
           StarsIn "Jack Nicholson" "Terms of Endearment",
           StarsIn "Sandra Bullock" "The Usual Suspects",
           StarsIn "Billy Bob Thornton" "The Man Who Wasn't There",
           StarsIn "Scarlett Johansson" "The Man Who Wasn't There", 
           StarsIn "Orlando Bloom" "The Fellowship of the Ring", 
           StarsIn "Cate Blanchett" "The Fellowship of the Ring", 
           StarsIn "Liv Tyler" "The Fellowship of the Ring"]

db :: MovieDB
db = (movies, stars, starsIn, studios, movieExecs)


-- getFeaturedStars "MGM" 1995 db → ["Jack Nicholson", "Sandra Bulloc"]
-- getFeaturedStars "USA Entertainm." 2001 db → ["Billy Bob Thornton", "Scarlett Johansson", "Orlando Bloom", "Cate Blanchett", "Liv Tyler"]
-- getPresident "Paramount" db → "Calvin Coolidge" 
-- getPresident "Fox" db → "Ted Turner"
-- getPresident "USA Entertainm." db → "Stephen Spielberg"
-- getHigherProductions "Calvin Coolidge" db → ["Pretty Woman",
-- "The Man Who Wasn't There","Logan's run","Star Wars", "Empire Strikes Back","Star Trek","The Usual Suspects", "The Fellowship of the Ring"]
-- getHigherProductions "Stephen Spielberg" db → ["Pretty Woman",
-- "The Man Who Wasn't There","Logan's run","Star Wars", "Empire Strikes Back","The Usual Suspects"]
-- getHigherProductions "George Lucas" db → []


data BTree a = Nil | Node a (BTree a) (BTree a) deriving Show

t1 :: BTree Char
t1 = Node 'a' (Node 'b' Nil (Node 'd' Nil Nil)) (Node 'c' (Node 'f' (Node 'e' Nil Nil) Nil) Nil)

t2 :: BTree Int
t2 = Node 10 (Node 5 (Node 3 (Node 1 Nil Nil) Nil) (Node 7 (Node 6 Nil Nil) Nil)) (Node 15 (Node 13 Nil Nil) (Node 18 Nil Nil))

toBinaryIndexed :: (Eq a) => BTree a -> BTree (a,Int)
toBinaryIndexed t = helper t 0
  where
    helper Nil current = Nil
    helper (Node x lt rt) current = Node (x, ((countNodes lt) + current)) (helper lt current) (helper rt (current + (countNodes lt) + 1))
      where
        countNodes Nil = 0;
        countNodes (Node x lt rt) = 1 + (countNodes lt) + (countNodes rt)
