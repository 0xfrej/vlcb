package doxygen

import (
	"regexp"
	"strings"
)

type Comment struct {
	Raw     string
	Remarks []string
	Brief   string
}

func ParseComment(comment string) (Comment, error) {
	var c Comment
	c.Raw = comment

	briefRegex, err := regexp.Compile(`@brief\s+(.*)`)
	if err != nil {
		return c, err
	}
	remarkRegex, err := regexp.Compile(`@remark\s+(.*)`)
	if err != nil {
		return c, err
	}

	{
		briefMatch := briefRegex.FindStringSubmatch(comment)
		if len(briefMatch) > 1 {
			c.Brief = strings.TrimSpace(briefMatch[1])
		}
	}

	{
		remarkMatches := remarkRegex.FindAllStringSubmatch(comment, -1)
		remarks := []string{}
		for _, match := range remarkMatches {
			if len(match) > 1 {
				remarks = append(remarks, strings.TrimSpace(match[1]))
			}
		}
		c.Remarks = remarks
	}

	return c, nil
}
