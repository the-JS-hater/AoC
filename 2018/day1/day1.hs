main :: IO ()
main = do
  contents <- readFile "input.txt"
  let intList = map (read . filter (/='+')) (lines contents) :: [Integer]
  let result = solve 0 intList
  print result

solve :: Integer -> [Integer] -> Integer
solve n [] = n
solve n (x : xs) = solve (n + x) xs
