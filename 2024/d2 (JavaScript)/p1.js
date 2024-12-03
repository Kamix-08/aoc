import { readData } from "./d2.js"

(async function main() {
    const inputData = await readData()

    let safe = 0

    for (const report of inputData)
    {
        if(report[0] == report[1])
            continue

        const increasing = (report[1] > report[0])
        let fine = true

        for(let i=1; i<report.length; i++)
        {
            const dist = Math.abs(report[i] - report[i-1])

            if(dist < 1 || dist > 3 || report[i] > report[i-1] != increasing)
            {
                fine = false
                break
            }
        }

        if(fine)
            ++safe
    }

    console.log(safe)
})()