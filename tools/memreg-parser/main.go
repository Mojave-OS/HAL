package main

import (
	"fmt"
	"os"
	"strings"
	"sync"
)

func parse_regfile(dat []byte, wg *sync.WaitGroup) {
	defer wg.Done()

	// we are going to first remove all comments
	for _, line := range strings.Split(string(dat), "\n") {
		line = strings.Trim(line, " ")

		// ignore comments
		if len(line) > 2 && line[:2] == "//" {
			continue
		}

	}

	println("Done parsing!")
}

func main() {
	var reglists [][]byte
	fmt.Println("Starting the parser...")

	files, err := os.ReadDir("../../include")
	if err != nil {
		panic(err)
	}

	for _, file := range files {
		if strings.Contains(strings.Split(file.Name(), ".")[1], "reglist") {
			fmt.Printf("Collected %s\n", file.Name())
			dat, err := os.ReadFile(fmt.Sprintf("../../include/%s", file.Name()))
			if err != nil {
				panic(err)
			}

			reglists = append(reglists, dat)
		}
	}

	// begin parsing
	wg := sync.WaitGroup{}
	for _, dat := range reglists {
		wg.Add(1)
		go parse_regfile(dat, &wg)
	}

	wg.Wait()
}
