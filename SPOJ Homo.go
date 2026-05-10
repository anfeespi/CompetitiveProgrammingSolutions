package main
import "fmt"

func main() {
    var t, v int
    var s string
    
    fmt.Scanf("%d", &t)
    
    set := make(map[int]int)
    list := []int{}
    for ; t > 0; t-- {
        
        fmt.Scanf("%s %d", &s, &v)
        
        if s == "insert" {
            list = append(list, v)
            set[v] = set[v]+1
        }else {
            for i := 0; i < len(list); i++ {
                if list[i] == v {
                    list[i] = list[len(list)-1]
                    list    = list[:len(list)-1]
                    break
                }
            }
            set[v] = set[v] - 1
            if set[v] <= 0 {
                delete(set,v)
            }
        }
        
        homo, hete := false, false
        
        if len(set) != len(list) {
            homo = true
        }
        if len(set) > 1 {
            hete = true;
        }
        
        if !homo && !hete {
            fmt.Println("neither")
        } else if homo && hete {
            fmt.Println("both")
        } else if homo {
            fmt.Println("homo")
        } else {
            fmt.Println("hetero")
        }
    }
}
