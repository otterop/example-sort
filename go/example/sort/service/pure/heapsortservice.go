package pure

import (
    otteropservice "github.com/otterop/example-sort/go/example/sort/service"
    otteroplang "github.com/otterop/otterop/go/lang"
)

type HeapsortService struct {
    otterop *otteropservice.HeapsortService
}


func HeapsortServiceWrap(otterop *otteropservice.HeapsortService) *HeapsortService {
    ret := new(HeapsortService)
    ret.otterop = otterop
    return ret
}


func HeapsortServiceNew() *HeapsortService {
    ret := new(HeapsortService)
    ret.otterop = otteropservice.HeapsortServiceNew()
    return ret
}



func (this *HeapsortService) Sort(array []*string) []*string {
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

func (this *HeapsortService) Unwrap() *otteropservice.HeapsortService {
    return this.otterop
}
