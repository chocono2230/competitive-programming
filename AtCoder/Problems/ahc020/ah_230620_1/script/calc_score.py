def ld(file):
    res_arr = []
    with open(file) as f:
        for line in f:
            res_arr.append({})
            arr = line.split(",")
            for st in arr:
                [key, val] = st.split(":")
                res_arr[-1][key] = float(val)
    return res_arr


now_result = ld("./sh_artifacts/result.txt")
sc = 0
for i in range(len(now_result)):
    print(
        now_result[i]["case"],
        now_result[i]["score"],
    )
    sc += now_result[i]["score"]
print("total score:", sc)
