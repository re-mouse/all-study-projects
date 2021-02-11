minikube start --vm-driver=virtualbox
minikube addons enable metallb
minikube dashboard &
eval $(minikube docker-env)
docker build -t nginx ./src/nginx
docker build -t grafana ./src/grafana
docker build -t ftps ./src/ftps
docker build -t wordpress ./src/wp
docker build -t mysql ./src/mysql
docker build -t phpmyadmin ./src/phpmyadmin
docker build -t influxdb ./src/influxdb
kubectl apply -f src/metallb.yaml
kubectl apply -f src/nginx/nginx.yaml
kubectl apply -f src/mysql/mysql.yaml
kubectl apply -f src/wp/wp.yaml
kubectl apply -f src/phpmyadmin/phpmyadmin.yaml
kubectl apply -f src/ftps/ftps.yaml
kubectl apply -f src/grafana/grafana.yaml
kubectl apply -f src/influxdb/influxdb.yaml
bash src/startdashboard