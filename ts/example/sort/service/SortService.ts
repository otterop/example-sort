import { Array } from '@otterop/lang/array';
import { String } from '@otterop/lang/string';

export interface SortService{
    sort(array : Array<String>) : Array<String>;
}

