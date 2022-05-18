/*

BoyerMooreMatching(pattern[0..m-1], text[0..n-1])
    i <- m-1;
    createBadTable(pattern[0..m-1], alphabet[0..])
    createGoodTable(pattern[0..m-1])

    while i <= n-1 do
        k <- 0
        while k <= m-1 and pattern[m-1-k] = text[i-k] do
            k <- k+1
        if k = m
            return i-m+1
        else
            if k = 0 
                i <- badTable[text[i-k]]-k
            else
                if badTable[text[i-k]]-k > goodTable[k-1]
                    i <- badTable[text[i-k]]-k
                else
                    i <- goodTable[k-1]
    return -1

*/