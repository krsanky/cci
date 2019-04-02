package main

import (
	"fmt"
	"os"
	"reflect"

	"github.com/krsanky/cci/go/c01"
	"github.com/krsanky/cci/go/c17"
)

func All() {

	c01.Q01()
	c01.Q02()
	c01.Q03()

	c17.Q19()

	//s := "asdd"
	//s[1] = '0'
	//fmt.Println(s)
	// string types are immutable, so if you want to modify the contents
	// of the buffer you'll need to use a []byte.
	s := "asd"
	fmt.Printf("type:%v\n", reflect.TypeOf(s))

	v1 := []string{"asd", "qwe", "123"}
	v2 := [4]string{"asd", "qwe", "123"}
	fmt.Printf("type:%v\n", reflect.TypeOf(v1))
	fmt.Printf("type:%v\n", reflect.TypeOf(v2))
}

func main() {
	fmt.Printf("cci <chapter> <question>\n")
	fmt.Printf("args:%s %d\n", os.Args[0], len(os.Args))
	if len(os.Args) != 3 {
		fmt.Printf("usage: %s <chapter> <question>\n", os.Args[0])
		os.Exit(1)
	}
}
