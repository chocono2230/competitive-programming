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

def read_times(file):
    res_arr = []
    with open(file) as f:
        for line in f:
            res_arr.append({})
            arr = line.split(",")
            for i in range(len(arr)-1):
                [key, val] = arr[i].split(":")
                if key == "case":
                    res_arr[-1]["case"] = int(val)
                    continue
                [nx_key, nx_val] = arr[i+1].split(":")
                add_key = key + "-" + nx_key
                if add_key not in res_arr[-1]:
                    res_arr[-1][add_key] = []
                res_arr[-1][add_key].append((float(nx_val) - float(val))*1000)
    return res_arr


now_result = ld("./sh_artifacts/result.txt")
sc = 0
for i in range(len(now_result)):
    print(
        "case: %d, score: %f" % (
        now_result[i]["case"],
        now_result[i]["score"])
    )
    sc += now_result[i]["score"]
print("total score:", sc)
print("100 scale: " + str(sc * 100 / len(now_result)))

# now_times = read_times("./sh_artifacts/time.txt")
# for obj in now_times:
#     for key in obj:
#         if key == "case":
#             continue
#         print("case: %d,\t%s:\t%f,\tsum: %f,  count: %d" % (obj["case"], key, sum(obj[key]) / len(obj[key]), sum(obj[key]), len(obj[key])))