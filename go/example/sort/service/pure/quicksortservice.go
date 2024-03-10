package pure

import (
    otteropservice "github.com/otterop/example-sort/go/example/sort/service"
    otteroplang "github.com/otterop/otterop/go/lang"
)

type QuicksortService struct {
    otterop *otteropservice.QuicksortService
}


func QuicksortServiceWrap(otterop *otteropservice.QuicksortService) *QuicksortService {
    ret := new(QuicksortService)
    ret.otterop = otterop
    return ret
}


func QuicksortServiceNew() *QuicksortService {
    ret := new(QuicksortService)
    ret.otterop = otteropservice.QuicksortServiceNew()
    return ret
}



func (this *QuicksortService) Sort(array []*string) []*string {
    var _arrayArray = make([]*otteroplang.String, len(array))
    for i := 0; i < len(array); i++ {
        _arrayArray[i] = otteroplang.StringWrap(array[i])
    }
    var _array = otteroplang.ArrayWrap(_arrayArray);
    retOtterop := this.otterop.Sort(_array)
    ret := make([]*string, retOtterop.Size())
    for i := 0; i < retOtterop.Size(); i++ {
        retI := retOtterop.Get(i)
        ret[i] = retI.Unwrap()
    }
    return ret
}

func (this *QuicksortService) Unwrap() *otteropservice.QuicksortService {
    return this.otterop
}
