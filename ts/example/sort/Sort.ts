import { HeapsortService } from './service/HeapsortService';
import { QuicksortService } from './service/QuicksortService';
import { SortService } from './service/SortService';
import { Array } from '@otterop/lang/array';
import { String } from '@otterop/lang/string';
import { Result } from '@otterop/lang/result';
import { Console } from '@otterop/io/console';
const { println } = Console;

export class Sort {

    private static _TEST : number = 111;

    static main(args : string[]) : void {
        let quick : String = String.wrap("quick");
        let heap : String = String.wrap("heap");
        let argsArray : Array<String> = Array.wrapString(args);
        
        if (argsArray.size() < 1) {
            println(String.wrap("Usage: <quick|heap> ...values"));
            return ;
        }
        let sortAlgorithm : String = argsArray.get(0);
        let isQuick : boolean = sortAlgorithm.compareTo(quick) == 0;
        let isHeap : boolean = sortAlgorithm.compareTo(heap) == 0;
        
        if (!(isQuick || isHeap)) {
            println(String.wrap("Usage: <quick|heap> ...values"));
            return ;
        }
        argsArray = argsArray.slice(1, argsArray.size());
        let sortService : SortService = new QuicksortService();
        
        if (isHeap) {
            sortService = new HeapsortService();
        }
        let ret : Array<String> = sortService.sort(argsArray);
        for (let i : number = 0; i < ret.size(); i++) {
            println(ret.get(i));
        }
        Result.of(String.wrap(""), String.wrap(""));
    }
}

Sort.main(process.argv.slice(2));