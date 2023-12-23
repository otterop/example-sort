import { SortService } from './service/pure/SortService';
import { HeapsortService } from './service/pure/HeapsortService';
import { QuicksortService } from './service/pure/QuicksortService';
import { Node } from './tree/pure/Node';

function main() {
    let args = process.argv.slice(2);
    if (args.length < 1) {
        console.log("Usage: <quick|heap> ...values");
        return;
    }
    const sortAlgorithm = args[0];
    const isQuick = sortAlgorithm === "quick";
    const isHeap = sortAlgorithm === "heap";
    if (!(isQuick || isHeap)) {
        console.log("Usage: <quick|heap> ...values");
        return;
    }
    args = args.slice(1);
    let sortService : SortService = new QuicksortService();
    if (isHeap)
        sortService = new HeapsortService();
    args = sortService.sort(args);
    for (let arg of args) {
        console.log(arg);
    }

    const a = new Node(1, []);
    const b = new Node(2, []);
    const c = new Node(3, [a,b]);
    const d = new Node(4, []);
    const e = new Node(5, []);
    const f = new Node(6, [d,e]);
    const g = new Node(7, [c,f]);

    let list = [g]
    while (list.length > 0) {
        const newList = [];
        let rest = false;
        for (let el of list) {
            if (rest)
                process.stdout.write(' ')
            process.stdout.write(`value: ${el.value()}`);
            for (let child of el.children()) {
                newList.push(child);
            }
            rest = true;
        }
        process.stdout.write('\n');
        list = newList;
    }
}

if (require.main === module) {
    main();
}
