import { QuicksortService } from './service/QuicksortService';
import { SortService } from './service/SortService';
import { Array } from '@otterop/lang/array';
import { String } from '@otterop/lang/string';
import { Result } from '@otterop/lang/result';
import { Console } from '@otterop/io/console';
const { println } = Console;

export class Sort {

    public static main(args : string[]) : void {
        let argsArray = Array.wrapString(args);
        let sortService = new QuicksortService();
        sortService.sort(argsArray, 0, argsArray.size());
        for (let i = 0; i < argsArray.size(); i++) {
            println(argsArray.get(i));
        }
        Result.of(String.wrap(""), String.wrap(""));
    }
}

Sort.main(process.argv.slice(2));