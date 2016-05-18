
void static inline bi_bw(int len, perf_metrics_t *metric_info)
{
    double start = 0.0, end = 0.0;
    int dest = partner_node(*metric_info);
    int i = 0, j = 0;

    shmem_barrier_all();

    if (streaming_node(*metric_info)) {
        for (i = 0; i < metric_info->trials + metric_info->warmup; i++) {
            if(i == metric_info->warmup)
                start = perf_shmemx_wtime();

            for(j = 0; j < metric_info->window_size; j++)
                shmem_putmem(metric_info->dest, metric_info->src, len, dest);

            shmem_quiet();
        }
        end = perf_shmemx_wtime();

        calc_and_print_results((end - start), len, *metric_info);

    } else {
        for (i = 0; i < metric_info->trials + metric_info->warmup; i++) {
            for(j = 0; j < metric_info->window_size; j++)
                shmem_putmem(metric_info->dest, metric_info->src, len, dest);

            shmem_quiet();
        }
    }
}
