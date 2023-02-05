import { QuicksortService } from './service/QuicksortService';
import { Array } from '@otterop/lang/array';
import { String } from '@otterop/lang/string';
import { Console } from '@otterop/io/console';
const { println } = Console;

export class Quicksort {

    public static main(args : string[]) : void {
        let argsArray = Array.wrapString(args);
        QuicksortService.quickSort(argsArray, 0, argsArray.size());
        let i = 0;
        
        while (i < argsArray.size()) {
            println(argsArray.get(i));
            i = i + 1;
        }
    }
}

Quicksort.main(process.argv.slice(2));