main = do
n <- readLn
let loop mSize mCap 0 = print (mCap - mSize)
    loop mSize mCap n = do
        [t, k] <- fmap (map read . words) getLine
        let mSize' = if t == 0 then mSize + k else mSize - k
        loop mSize' (until (>= mSize') (* 2) mCap) (n - 1)
loop 0 1 n