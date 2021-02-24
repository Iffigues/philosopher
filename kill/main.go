package main

import (
	"io/ioutil"
	"os"
	"regexp"
	"strconv"
	"strings"
)

func main() {
	mui := os.Args[1]
	space := regexp.MustCompile(`\s+`)
	m, _ := ioutil.ReadFile("./w")
	mm := strings.Split(string(m), "\n")
	for _, val := range mm {
		if len(val) > 0 {
			ll := strings.TrimSpace(val)
			kl := space.ReplaceAllString(ll, " ")
			kk := strings.Split(kl, " ")
			if kk[4] == mui {
				b, _ := strconv.Atoi(kk[0])
				e, _ := os.FindProcess(b)
				e.Kill()
			}
		}
	}
	/*b, _ := strconv.Atoi(h)
	e, _ := os.FindProcess(b)
	fmt.Println(e)
	e.Kill()*/
}
