package arrays

func Filter[T any](a []T, predicate func(T) bool) []T {
	var result []T
	for _, v := range a {
		if predicate(v) {
			result = append(result, v)
		}
	}
	return result
}
