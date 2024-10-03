package main
import (
    "fmt"
    "math"
)
func main() {
	var n float64
	fmt.Scan(&n)
	fmt.Print(math.Pow(2,math.Ceil(math.Log2(n))) - n)
}