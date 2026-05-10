package main
import "fmt"
import "io"

var mem = make(map[int64]int64)

func max(a, b int64) int64{
    if a > b {
        return a
    }
    
    return b
}

func rec(n int64) int64 {
    if n == 0 {
        return 0
    }
    
    if v, ok := mem[n]; ok {
        return v
    }
    
    ret := max(n, rec(n/2) + rec(n/3) + rec(n/4))
    mem[n] = ret
    
    return ret
}

func main() {
    var n int64
    
    for {
        _, err := fmt.Scan(&n)
        if err == io.EOF {
            break
        }
        
        fmt.Println(rec(n))
    }
}
