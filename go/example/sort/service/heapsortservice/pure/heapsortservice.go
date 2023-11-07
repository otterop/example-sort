package pure

import (
    otteropheapsortservice "github.com/otterop/example-sort/go/example/sort/service/heapsortservice"
    otteroparray "github.com/otterop/otterop/go/lang/array"
    otteropstring "github.com/otterop/otterop/go/lang/string"
)

type HeapsortService struct {
    otterop *otteropheapsortservice.HeapsortService
}


func Wrap(otterop *otteropheapsortservice.HeapsortService) *HeapsortService {
    ret := new(HeapsortService)
    ret.otterop = otterop
    return ret
}


func NewHeapsortService() *HeapsortService {
    ret := new(HeapsortService)
    ret.otterop = otteropheapsortservice.NewHeapsortService()
    return ret
}



func (this *HeapsortService) Sort(array []*string) []*string {
    var _arrayArray = make([]*otteropstring.String, len(array))
    for i := 0; i < len(array); i++ {
        _arrayArray[i] = otteropstring.Wrap(array[i])
    }
    var _array = otteroparray.Wrap(_arrayArray);
    retOtterop := this.otterop.Sort(_array)
    ret := make([]*string, retOtterop.Size())
    for i := 0; i < retOtterop.Size(); i++ {
        retI := retOtterop.Get(i)
        ret[i] = retI.Unwrap()
    }
    return ret
}

func (this *HeapsortService) Unwrap() *otteropheapsortservice.HeapsortService {
    return this.otterop
}
