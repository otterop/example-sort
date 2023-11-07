package pure

import (
    otteropquicksortservice "github.com/otterop/example-sort/go/example/sort/service/quicksortservice"
    otteroparray "github.com/otterop/otterop/go/lang/array"
    otteropstring "github.com/otterop/otterop/go/lang/string"
)

type QuicksortService struct {
    otterop *otteropquicksortservice.QuicksortService
}


func Wrap(otterop *otteropquicksortservice.QuicksortService) *QuicksortService {
    ret := new(QuicksortService)
    ret.otterop = otterop
    return ret
}


func NewQuicksortService() *QuicksortService {
    ret := new(QuicksortService)
    ret.otterop = otteropquicksortservice.NewQuicksortService()
    return ret
}



func (this *QuicksortService) Sort(array []*string) []*string {
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

func (this *QuicksortService) Unwrap() *otteropquicksortservice.QuicksortService {
    return this.otterop
}
