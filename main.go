package main

import (
	"fmt"
	"reflect"

	"github.com/krsanky/cci/chap1"
)

func main() {
	fmt.Println("cci")
	chap1.Q1()
	chap1.Q2()
	chap1.Q3()

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
